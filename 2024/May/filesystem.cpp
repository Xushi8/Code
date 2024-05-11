#include <string>
#include <vector>
#include <cstddef>
#include <unordered_map>
#include <fstream>
#include <fmt/format.h>
#include <iostream>
#include <algorithm>
#include <unordered_set>
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
	char* read_ptr = nullptr;
	char* write_ptr = nullptr;

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
			}
		}
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

struct MDF
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
			}
		}
	}
};

void read(MDF& mdf)
{
	ifstream ifs("mdf.in");
	
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

int main()
{
	MDF mdf;
	read(mdf);
	

	print("Please enter username\n");
	string username;
	cin >> username;
	auto it = mdf.UFDs.find(username);
	if (it == mdf.UFDs.end())
	{
		print(stderr, "Username not found!\n");
		exit(1);
	}

	UFD* ufd = it->second;
	ufd->print();

	AFD afd;
	print("Enter command: ");
	string op;
	while (cin >> op)
	{
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
				continue;
			}

			afd.insert({file_name});
		}
		else if (op == "close")
		{
		}
		else if (op == "read")
		{
		}
		else if (op == "write")
		{
		}
		else if (op == "dir")
		{
			ufd->print();
		}
		else
		{
			print(stderr, "Please enter right command\n");
		}
	}

	return 0;
}
