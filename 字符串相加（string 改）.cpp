class Solution
{
public:
	string addStrings(string num1, string num2)
	{
		string strret;
		int end1 = num1.size() - 1, end2 = num2.size() - 1;
		int step = 0;

		while (end1 >= 0 || end2 >= 0)
		{
			int val1, val2, addret;

			if (end1 >= 0)
            {
                val1 = num1[end1] - '0';
            }
			else
            {
				val1 = 0;
            }

			if (end2 >= 0)
            {
				val2 = num2[end2] - '0';
            }
			else
            {
				val2 = 0;
            }

			addret = val1 + val2 + step;
			if (addret > 9)
			{
				addret -= 10;
				step = 1;
			}
			else
			{
				step = 0;
			}

			strret += addret + '0';
            --end1;
            --end2;
		}

		if (step)
		{
			strret += '1';
		}

		reverse(strret.begin(), strret.end());
		return strret;
	}
};
