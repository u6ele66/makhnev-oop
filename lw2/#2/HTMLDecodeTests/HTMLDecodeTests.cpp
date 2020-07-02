#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../HTMLDecode/Decode.h"

TEST_CASE("Replacer should return empty string")
{
	string empty = "";
	CHECK(ReplaceEntity(empty, "\"", "&quot;").empty());
}

TEST_CASE("Decoder should return empty string")
{
	string empty = "";
	CHECK(HtmlDecode(empty).empty());
}

TEST_CASE("Replace single entity")
{
	string quot = "&quot; hello!";
	string apos = "&apos; hello!";
	string lt = "&lt; hello!";
	string gt = "&gt; hello!";
	string amp = "&amp; hello!";
	CHECK(ReplaceEntity(quot, "\"", "&quot;") == "\" hello!");
	CHECK(ReplaceEntity(apos, "'", "&apos;") == "' hello!");
	CHECK(ReplaceEntity(lt, "<", "&lt;") == "< hello!");
	CHECK(ReplaceEntity(gt, ">", "&gt;") == "> hello!");
	CHECK(ReplaceEntity(amp, "&", "&amp;") == "& hello!");
}

TEST_CASE("Decode single entity")
{
	string quot = "&quot; hello!";
	string apos = "&apos; hello!";
	string lt = "&lt; hello!";
	string gt = "&gt; hello!";
	string amp = "&amp; hello!";
	CHECK(HtmlDecode(quot) == "\" hello!");
	CHECK(HtmlDecode(apos) == "' hello!");
	CHECK(HtmlDecode(lt) == "< hello!");
	CHECK(HtmlDecode(gt) == "> hello!");
	CHECK(HtmlDecode(amp) == "& hello!");
}

TEST_CASE("Decode all entities")
{
	string text = "Hello! &amp; How &quot;are &lt;&gt;&apos;u";
	CHECK(HtmlDecode(text) == "Hello! & How \"are <>'u");
}

TEST_CASE("Replace repetitive entities")
{
	string text = "&amp;&amp;&amp;";
	CHECK(ReplaceEntity(text, "&", "&amp;") == "&&&");
}

TEST_CASE("Decode repetitive entities")
{
	string text = "&amp;&amp;&amp;";
	CHECK(HtmlDecode(text) == "&&&");
}

TEST_CASE("String without entities try to replace")
{
	string text = "Hello world!";
	CHECK(ReplaceEntity(text, "\"", "&quot;") == text);
	CHECK(ReplaceEntity(text, "'", "&apos;") == text);
	CHECK(ReplaceEntity(text, "<", "&lt;") == text);
	CHECK(ReplaceEntity(text, ">", "&gt;") == text);
	CHECK(ReplaceEntity(text, "&", "&amp;") == text);
}

TEST_CASE("String without entities try to decode")
{
	string text = "Hello world!";
	CHECK(HtmlDecode(text) == text);
	CHECK(HtmlDecode(text) == text);
	CHECK(HtmlDecode(text) == text);
	CHECK(HtmlDecode(text) == text);
	CHECK(HtmlDecode(text) == text);
}