#include <string>
#include <vector>
#include <cstddef>
#include <unordered_map>
#include <fstream>
#include <fmt/format.h>
#include <iostream>
#include <unordered_set>
#include <fmt/os.h>
using std::string;
using std::vector;
using std::unordered_map;
using std::ifstream;
using fmt::print;
using std::cin;
using std::unordered_set;
using std::string_view;

struct file
{
	string name;
	bool readable = true;
	bool writable = true;
	bool executable = false;
	size_t len = 0;

	bool operator==(file const& that) const = default;

	void print() const
	{
		fmt::print("{}\t{:d}{:d}{:d}\t{}\n", name, readable, writable, executable, len);
	}
};

struct openfile
{
	string name;
	bool readable = true;
	bool writable = true;
	bool executable = false;
	size_t len = 0;
	char* read_ptr = nullptr;
	char* write_ptr = nullptr;

	openfile(file const& f) :
		name(f.name), readable(f.readable), writable(f.writable),
		executable(f.executable) {}

	bool operator==(openfile const& that) const = default;
};

struct UFD
{
	vector<file> files;
	unordered_set<string> names;

	void insert(file const& val)
	{
		files.emplace_back(val);
		names.emplace(val.name);
	}

	void erase(file const& val)
	{
		this->erase(val.name);
	}

	void erase(string_view name)
	{
		names.erase(name.data());
		for (auto it = files.begin(); it != files.end(); it++)
		{
			if (it->name == name)
			{
				files.erase(it);
				break;
			}
		}
	}

	file& get(string_view name)
	{
		for (auto&& x : files)
		{
			if (x.name == name)
			{
				return x;
			}
		}

#if defined(__GNUC__) || defined(__clang__)
		__builtin_unreachable();
#endif
	}

	void print() const
	{
		fmt::print("FileName Protect Length\n");
		for (auto const& x : files)
		{
			x.print();
		}
	}
};

struct MFD
{
	unordered_map<string, UFD*> UFDs;
};

struct AFD
{
	vector<openfile> openfiles;
	unordered_set<string> names;

	void insert(openfile const& file)
	{
		openfiles.emplace_back(file);
		names.emplace(file.name);
	}

	void erase(openfile const& file)
	{
		this->erase(file.name);
	}

	void erase(string_view name)
	{
		names.erase(name.data());
		for (auto it = openfiles.begin(); it != openfiles.end(); it++)
		{
			if (it->name == name)
			{
				openfiles.erase(it);
				break;
			}
		}
	}

	void read(string_view name)
	{
		for (auto it = openfiles.begin(); it != openfiles.end(); it++)
		{
			if (it->name == name)
			{
				if (!it->readable)
				{
					print(stderr, "You doesn't have read permisio\n");
					break;
				}
				it->read_ptr++;
				break;
			}
		}
	}

	void write(string_view name)
	{
		for (auto it = openfiles.begin(); it != openfiles.end(); it++)
		{
			if (it->name == name)
			{
				if (!it->writable)
				{
					print(stderr, "You doesn't have write permision\n");
					break;
				}
				it->write_ptr++;
				it->len++;
				break;
			}
		}
	}

	openfile& get(string_view name)
	{
		for (auto&& x : openfiles)
		{
			if (x.name == name)
			{
				return x;
			}
		}

#if defined(__GNUC__) || defined(__clang__)
		__builtin_unreachable();
#endif
	}
};

void read(MFD& mfd)
{
	ifstream ifs("mfd.in");
	string s;
	string name;
	UFD* t;
	while (ifs >> s)
	{
		if (s.starts_with("User:"))
		{
			t = new UFD;
			name = s.substr(5);
			mfd.UFDs[name] = t;
		}
		else
		{
			string file_name = s;
			file f(s);
			// ifs >> f.readable >> f.writable >> f.executable >> f.len;
			char r, w, x;
			ifs >> r >> w >> x >> f.len;
			f.readable = r - '0';
			f.writable = w - '0';
			f.executable = x - '0';
			t->insert(std::move(f));
		}
	}
}

void write(MFD mfd)
{
	fmt::ostream out = fmt::output_file("mfd.in");
	for (auto [username, t] : mfd.UFDs)
	{
		out.print("User:{}\n", username);
		for (auto file : t->files)
		{
			out.print("{} {:d}{:d}{:d} {}\n", file.name, file.readable, file.writable, file.executable, file.len);
		}
		out.print("\n");
	}
}

void menu()
{
	print("Bye: exit program\n");
	print("create: create a file\n");
	print("delete: delete a file\n");
	print("open: open a file\n");
	print("close: close a file\n");
	print("read: read a file\n");
	print("write: write a file\n");
}

void press_continue()
{
	cin.ignore(INT64_MAX, '\n');
	print("Press enter to continue\n");
	cin.get();
	print("\033[2J\033[H");
}

int main()
{
	MFD mfd;
	read(mfd);

	print("Please enter username: ");
	string username;
	cin >> username;
	auto it = mfd.UFDs.find(username);
	if (it == mfd.UFDs.end())
	{
		print(stderr, "Username not found!\n");
		exit(1);
	}

	UFD* ufd = it->second;

	AFD afd;
	string op;
	while (1)
	{
		ufd->print();
		print("\n");
		menu();
		print("\n");
		print("Enter command: ");
		cin >> op;
		if (op == "Bye")
		{
			break;
		}

		if (op == "create")
		{
			string file_name;
			print("Enter file name: ");
			cin >> file_name;
			if (ufd->names.contains(file_name))
			{
				print(stderr, "File {} already exist!\n", file_name);
				press_continue();
				continue;
			}

			ufd->insert({file_name});
		}
		else if (op == "delete")
		{
			string file_name;
			print("Enter file name: ");
			cin >> file_name;
			if (!ufd->names.contains(file_name))
			{
				print(stderr, "File {} not found!\n", file_name);
				press_continue();
				continue;
			}

			ufd->erase(file_name);
			if (afd.names.contains(file_name))
			{
				afd.erase(file_name);
			}
		}
		else if (op == "open")
		{
			string file_name;
			print("Enter file name: ");
			cin >> file_name;
			if (!ufd->names.contains(file_name))
			{
				print(stderr, "File {} not found!\n", file_name);
				press_continue();
				continue;
			}

			auto& file = ufd->get(file_name);
			afd.insert(file);
		}
		else if (op == "close")
		{
			string file_name;
			print("Enter file name: ");
			cin >> file_name;
			if (!ufd->names.contains(file_name))
			{
				print(stderr, "File {} not found!\n", file_name);
				press_continue();
				continue;
			}

			if (!afd.names.contains(file_name))
			{
				print(stderr, "File {} doesn't open\n", file_name);
				press_continue();
				continue;
			}

			afd.erase(file_name);
		}
		else if (op == "read")
		{
			string file_name;
			print("Enter file name: ");
			cin >> file_name;
			if (!ufd->names.contains(file_name))
			{
				print(stderr, "File {} not found!\n", file_name);
				press_continue();
				continue;
			}

			if (!afd.names.contains(file_name))
			{
				print(stderr, "File {} doesn't open\n", file_name);
				press_continue();
				continue;
			}

			afd.read(file_name);
		}
		else if (op == "write")
		{
			string file_name;
			print("Enter file name: ");
			cin >> file_name;
			if (!ufd->names.contains(file_name))
			{
				print(stderr, "File {} not found!\n", file_name);
				press_continue();
				continue;
			}

			if (!afd.names.contains(file_name))
			{
				print(stderr, "File {} doesn't open\n", file_name);
				press_continue();
				continue;
			}

			afd.write(file_name);
		}
		else if (op == "dir")
		{
			ufd->print();
		}
		else
		{
			print(stderr, "Please enter right command\n");
		}

		print("Press enter to continue\n");
		cin.ignore(INT64_MAX, '\n');
		cin.get();
		print("\033[2J\033[H");
	}

	ufd->print();
	write(mfd);

	return 0;
}
