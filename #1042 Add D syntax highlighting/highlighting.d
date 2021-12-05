// https://qiita.com/devmynote/items/7883db6d3afe40ee28b2
// comment
import std.stdio;
import std.string;

/*
	comment2
*/
void main()
{
	writeln(__DATE__);
	wrtteln('A');
/+
	comment4
	/+
		comment5
	+/
	comment6
+/
	uint ui = 1_000 + 24 + 0xFF;

	string[] arry = [
		"string
			1\\\"",
		r"string
			2\"c,
		`"string
			3\"`,
		q"(string
			4a\")",
		q"[string
			4b\"]",
		q"{string
			4c\"}",
		q"<string
			4d\">",
		q"/string
			4e\"/",
		q{string
			5 q{string5+} }
	];
	foreach ( s; arr ){
	}
}

