#include <fmt/format.h>
#include <pqxx/pqxx>
#include <string_view>
#include <chrono>
#include <tbb/tick_count.h>
using namespace std;
using namespace fmt;
using namespace pqxx;

void create_table(work& W)
{
	constexpr std::string_view sql = "CREATE TABLE person ("
									 "ID SERIAL PRIMARY KEY, "
									 "NAME TEXT NOT NULL, "
									 "AGE INT NOT NULL, "
									 "GENDER VARCHAR(5) NOT NULL);";
	print("{}\n", sql);
	W.exec(sql.data());
	W.commit();
	print("Create table succesfully!\n");
}

void insert_data(work& W)
{
	for (size_t i = 0; i < 10; i++)
	{
		std::string sql = format("INSERT INTO person (NAME, AGE, GENDER) "
								 "values('zhangsan', {}, 'man');",
			rand() % 100);
		W.exec(sql);
	}
	W.commit();
	print("Records created successfully!\n");
}

int main()
{
	try
	{
		// connection C("dbname = testdb user = tom password = tom hostaddr = ::1 port = 5432");
		connection C;
        
		if (C.is_open())
		{
			print("Open database succesfully: {}\n", C.dbname());

            work W(C);

			// create_table(W);
			auto first = tbb::tick_count::now();
			insert_data(W);
			auto last = tbb::tick_count::now();
			print("Time elapsed: {}s\n", (last - first).seconds());

			C.disconnect();
		}
		else
		{
			print(stderr, "Can't open database\n");
			exit(1);
		}
	}
	catch (pqxx::sql_error const& e)
	{
		print(stderr, "Database error: {}\nQuery was: {}\n", e.what(), e.query());
		exit(2);
	}
	catch (exception const& e)
	{
		print(stderr, "{}\n", e.what());
		exit(1);
    }
	return 0;
}