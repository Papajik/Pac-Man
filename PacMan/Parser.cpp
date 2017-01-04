#include "Parser.h"
#include <msclr\marshal_cppstd.h>
Parser::Parser()
{
}

int Parser::loadLevel(int x, MapContainer **array)
{
	ifstream in;
	switch (x)
	{
	case 1:
		in.open("../Level1");
		//in.open("C:/Users/Papi/Documents/Visual Studio 2015/Projects/PacMan/Level1");

		break;
	case 2:
		in.open("../Level2");
		break;
	default:
		break;
	}

	int score = 0;
	for (int i = 0; i < 11;i++)
	{
		for (int j = 0; j < 17;j++)
		{
			while (in.peek() == '\n')
			{
				in.get();
			}
			char a = in.get();
			switch (a)
			{
			case '1':
			{
				wchar_t a = L'█';
				MapObject* ob = new MapObject(1, a);
				array[i][j].addObject(ob);
				break;
			}
			case '2':
			{
				wchar_t b = L'O';
				ch = new Character(b);
				array[i][j].addObject(ch);
				break;
			}
			case '3':
			{
				wchar_t c = L'→';
				Ghost* gh = new Ghost(c);
				gh->setDirX(1);
				array[i][j].addObject(gh);
				break;
			}
			case '4':
			{
				score += 50;
				wchar_t d = L'+';
				Food* fo = new Food(50, d);
				array[i][j].addObject(fo);
				break;
			}
			}
			MapContainer con = array[i][j];
		}
	}
	in.close();
	return score;
}

Character* Parser::getCharacter()
{
	return ch;
}

System::String^ Parser::loadHighScore(System::String^ str, int lvl, int actualScore)
{
	ifstream stream("../HighScore");
	if (stream.is_open())
	{
		string s;
	}
	string s;
	System::String^ returnTo;
	System::String^ compareTo;
	switch (lvl)
	{
	case 1: compareTo = "Level 1";
		break;
	case 2: compareTo = "Level 2";
	}
	bool compare = false;
	
	int line = 0;
	while (!stream.eof()) {
		getline(stream, s);
		System::String^ ss;
		if (compare&&line<8)
		{
			ss = gcnew System::String(s.c_str());
			line++;
			if (compareScore(actualScore, ss ))
			{
				ss = "" + actualScore+"\n";
			}
		} else
		{ 
			ss = gcnew System::String(s.c_str());
		}

		if (ss == compareTo)
		{
			compare = true;
		}
		if (compare)
		str += ss + "\n";
	}
	
	stream.close();
	ofstream writer("../HighScore");
	writer <<	msclr::interop::marshal_as<std::string>(str);
	return str;
}

bool Parser::compareScore(int actual, System::String^ inFile)
{
	try {
		return actual > int::Parse(inFile);
	} catch (System::FormatException^ ex)
	{
		//means no score
		return true;
	}
}