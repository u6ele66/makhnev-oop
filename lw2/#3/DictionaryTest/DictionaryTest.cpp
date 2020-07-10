#include "../miniDictionary/Dictionary.h"
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE unit_tests
#include <boost/test/included/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>

BOOST_AUTO_TEST_SUITE(function_tests)

struct cout_redirect {
	cout_redirect(std::streambuf* new_buffer)
		: old(std::cout.rdbuf(new_buffer))
	{ }

	~cout_redirect() {
		std::cout.rdbuf(old);
	}

private:
	std::streambuf* old;
};

BOOST_AUTO_TEST_CASE(ReadDictionary_FILE_NOT_EXISTS)
{
	map<string, string> _dictionary;
	ReadDictionary(_dictionary);
	BOOST_TEST(_dictionary.empty());
	cout << "\"ReadDictionary\" file not exists - Test Passed!\n";
}

BOOST_AUTO_TEST_CASE(SaveChangesTest)
{
	setlocale(LC_ALL, "Russian");
	boost::test_tools::output_test_stream output;
	{
		cout_redirect guard(output.rdbuf());
		map<string, string> _dictionary = {
			{"hello", "Привет"}
		};
		SaveChanges(_dictionary);
	}
	BOOST_CHECK(output.is_equal(SUCCESSFUL_SAVING_MESSAGE));
	cout << "\"SaveChanges\" - Test Passed!\n";
}

BOOST_AUTO_TEST_CASE(ReadDictionary_FILE_EXISTS)
{
	map<string, string> _dictionary;
	map<string, string> _expected = {
		{"hello", "Привет"}
	};
	ReadDictionary(_dictionary);
	BOOST_TEST(_dictionary == _expected);
	cout << "\"ReadDictionary\" file exists - Test Passed!\n";
}

BOOST_AUTO_TEST_CASE(SaveTranslationTest)
{
	map<string, string> _dictionary = {
		{"hello", "Привет"}
	};
	map<string, string> _expected = {
		{"hello", "Привет"},
		{"road", "дорога"},
	};
	SaveTranslation(_dictionary, "road", "дорога");
	BOOST_TEST(_dictionary == _expected);
	cout << "\"SaveTranslation\" - Test Passed!\n";
}

BOOST_AUTO_TEST_CASE(SaveChanges_EmptyDictionary)
{
	map<string, string> _dictionary;
	SaveChanges(_dictionary);
	cout << "\"SaveChanges\" empty dictionary saving - Test Passed!\n";
	remove(DICTIONARY_FILENAME.c_str());
}
BOOST_AUTO_TEST_SUITE_END()