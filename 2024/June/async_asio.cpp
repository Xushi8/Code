#include <memory>
#include <fmt/core.h>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/read.hpp>
#include <boost/asio/signal_set.hpp>
using fmt::print;

struct A : public std::enable_shared_from_this<A>
{
	A(boost::asio::io_context& ctx) :
		m_ctx(ctx),
		m_acceptor(m_ctx, {boost::asio::ip::tcp::v6(), 1111}), m_socket(m_ctx)
	{
	}

	void accept()
	{
		m_acceptor.async_accept(m_socket, [self = shared_from_this()](std::error_code ec)
			{
				if (ec)
				{
					print(stderr, "accept error, val = {}, message = {}\n", ec.value(), ec.message());
				}
				else
				{
					print("accept good, val = {}, message = {}\n", ec.value(), ec.message());
					self->read();
				}
			});
	}

	void read()
	{
		m_socket.async_read_some(boost::asio::buffer(m_buffer), [self = shared_from_this()](std::error_code ec, size_t read_len)
			{
				if (ec)
				{
					print(stderr, "read error, val = {}, message = {}\n", ec.value(), ec.message());
				}
				else
				{
					print("good, read {}\n", std::string_view(self->m_buffer.data(), read_len));
					self->write(read_len);
				}
			});
	}

	void write(size_t len)
	{
		boost::asio::async_write(m_socket, boost::asio::const_buffer(m_buffer.data(), len), [self = shared_from_this()](std::error_code ec, [[maybe_unused]] size_t write_len)
			{
				if (ec)
				{
					print(stderr, "write error, val = {}, message = {}\n", ec.value(), ec.message());
				}
				else
				{
					print("write good\n", ec.value(), ec.message());
					self->read();
				}
			});
	}

	boost::asio::io_context& m_ctx;
	boost::asio::ip::tcp::acceptor m_acceptor;
	boost::asio::ip::tcp::socket m_socket;
	std::array<char, 1024> m_buffer;
};

int main()
{
	boost::asio::io_context ctx;
	boost::asio::signal_set signals(ctx, SIGINT, SIGTERM);
	signals.async_wait([&](auto, auto)
		{
			ctx.stop();
		});
	std::shared_ptr<A> a = std::make_shared<A>(ctx);
	a->accept();
	ctx.run();
	return 0;
}