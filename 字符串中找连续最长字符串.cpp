string s;
	string c;
	getline(cin, s);

	auto start = s.begin();
	auto end = start;
	while (end != s.end())
	{
		
		int max = 0;
		while (end != s.end() && (*end < 48 || *end > 57))
		{
			end++;
		}

		if (end != s.end())
		{
			start = end;
		}
		else
		{
			start = end;
		}

		while (end != s.end() && (*end >= 48 && *end <= 57))
		{
			max++;
			end++;
		}


		if ( max > c.size())
		{
			c.clear();
			while (start != end)
			{
				c += *start;
				start++;
			}
		}

		if (end == s.end())
		{
			break;
		}
	}
	cout << c<<endl;
