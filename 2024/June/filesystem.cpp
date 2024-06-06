#include <algorithm>
#include <fmt/core.h>
#include <filesystem>
#include <execution>
#include <numeric>
#include <tbb/parallel_for.h>
#include <tbb/parallel_reduce.h>
using namespace std;
using fmt::print;
namespace fs = std::filesystem;

int main()
{
	const fs::path home("/usr");

	size_t siz = 0;
	// for (auto const& dir_entry : fs::recursive_directory_iterator(home))
	// {
	// 	// print("{}\n", dir_entry.path().string());
	// 	if (fs::is_regular_file(dir_entry))
	// 	{
	// 		// print("{} byte\n", dir_entry.file_size());
	// 		siz += dir_entry.file_size();
	// 	}
	// }

	// ranges::for_each(fs::recursive_directory_iterator(home), [&](auto const& dir_entry)
	// 	{
	// 		// print("{}\n", dir_entry.path().string());
	// 		if (fs::is_regular_file(dir_entry))
	// 		{
	// 			// print("{} byte\n", dir_entry.file_size());
	// 			siz += dir_entry.file_size();
	// 		}
	// 	});

	// ranges::for_each(std::execution::par, fs::recursive_directory_iterator(home), [&](auto const& dir_entry)
	// 	{
	// 		// print("{}\n", dir_entry.path().string());
	// 		if (fs::is_regular_file(dir_entry))
	// 		{
	// 			// print("{} byte\n", dir_entry.file_size());
	// 			siz += dir_entry.file_size();
	// 		}
	// 	});

	auto recursive_it = fs::recursive_directory_iterator(home);
	// for_each(std::execution::par, begin(recursive_it), end(recursive_it), [&](auto const& dir_entry)
	// 	{
	// 		// print("{}\n", dir_entry.path().string());
	// 		if (fs::is_regular_file(dir_entry))
	// 		{
	// 			// print("{} byte\n", dir_entry.file_size());
	// 			siz += dir_entry.file_size();
	// 		}
	// 	});

	vector<fs::path> paths;
	copy(begin(recursive_it), end(recursive_it), std::inserter(paths, paths.begin()));

	// for_each(std::execution::par, begin(paths), end(paths), [&](auto const& dir_entry)
	// 	{
	// 		siz += fs::is_regular_file(dir_entry) ? fs::file_size(dir_entry) : 0;
	// 	});

	// siz = std::transform_reduce(std::execution::par_unseq, begin(paths), end(paths), siz, std::plus<>(), [&](auto const& dir_entry) -> size_t
	// 	{
	// 		return fs::is_regular_file(dir_entry) ? fs::file_size(dir_entry) : 0;
	// 	});

	// tbb::parallel_for(tbb::blocked_range<size_t>(0, paths.size()), [&](tbb::blocked_range<size_t> const& r)
	// 	{
	// 		for (size_t i = r.begin(); i != r.end(); i++)
	// 		{
	// 			siz += fs::is_regular_file(paths[i]) ? fs::file_size(paths[i]) : 0;
	// 		}
	// });

	siz = tbb::parallel_reduce(tbb::blocked_range<size_t>(0, paths.size()), siz, [&](tbb::blocked_range<size_t> const& r, size_t local_res)
		{
			for (size_t i = r.begin(); i != r.end(); i++)
			{
				// print("{}\n", paths[i].string());
				local_res += fs::is_regular_file(paths[i]) ? fs::file_size(paths[i]) : 0;
			}
			return local_res;
	}, std::plus<>());

	print("All size: {} bytes\n", siz);
	print("All size: {} kb\n", siz / 1024.L);
	print("All size: {} mb\n", siz / 1024.L / 1024);
	print("All size: {} gb\n", siz / 1024.L / 1024 / 1024);
}