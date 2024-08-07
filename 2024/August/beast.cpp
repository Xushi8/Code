#include <boost/beast/core/buffers_to_string.hpp>
#include <boost/beast/websocket/ssl.hpp>
#include <boost/beast/ssl/ssl_stream.hpp>
#include <memory>
#include <boost/beast/websocket/stream.hpp>
#include <boost/beast/core/tcp_stream.hpp>
#include <boost/asio/io_context.hpp>

template <typename stream_type>
struct connection : public std::enable_shared_from_this<connection<stream_type>>
{
    connection(boost::asio::io_context& ctx) :
        m_ws(ctx)
    {
        static_assert(std::is_same_v<stream_type, boost::beast::tcp_stream>, "ssl 必须添加ssl::context");
    }

    connection(boost::asio::io_context& ctx, boost::asio::ssl::context& ssl_ctx) :
        m_ws(ctx, ssl_ctx)
    {
        static_assert(std::is_same_v<stream_type, boost::beast::ssl_stream<boost::beast::tcp_stream>>, "普通 connection 不支持 ssl");
    }

    boost::beast::websocket::stream<stream_type> m_ws;
};

int main()
{
    namespace beast = boost::beast;         // from <boost/beast.hpp>
    namespace http = beast::http;           // from <boost/beast/http.hpp>
    namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
    namespace net = boost::asio;            // from <boost/asio.hpp>
    using tcp = net::ip::tcp;               // from <boost/asio/ip/tcp.hpp>

    std::string ssl_chain_file_path("/home/tom/Videos/server.crt"), ssl_key_file_path("/home/tom/Videos/server.key");

    net::io_context ctx{1};

    tcp::acceptor acceptor{ctx, {tcp::v6(), 8888}};

    boost::asio::ssl::context ssl_ctx(boost::asio::ssl::context::tlsv13);
    ssl_ctx.use_certificate_chain_file(ssl_chain_file_path);
    ssl_ctx.use_private_key_file(ssl_key_file_path, boost::asio::ssl::context::pem);

    // std::shared_ptr<connection<boost::beast::tcp_stream>> connection_ptr;
    // connection_ptr = std::make_shared<connection<boost::beast::tcp_stream>>(ctx);

    std::shared_ptr<connection<boost::beast::ssl_stream<boost::beast::tcp_stream>>> connection_ptr;
    connection_ptr = std::make_shared<connection<boost::beast::ssl_stream<boost::beast::tcp_stream>>>(ctx, ssl_ctx);
}