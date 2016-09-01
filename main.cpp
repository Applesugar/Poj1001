#include<iostream>
#include<string>
//using namespace std;
// we suppose that the input string only contains "0~9"and "."
std::string add(std::string a,std::string b)
{
	std::string sum;
	std::string sum_decimal;
	std::string sum_int;
	int a_length = a.length();
	int b_length = b.length();
//	std::cout << a_length << " " << b_length << std::endl;
	int a_dot_num = a.find_first_of('.');
	int b_dot_num = b.find_first_of('.');
//	std::cout << a_dot_num<<" "<<b_dot_num << std::endl;
	std::string a_int_part, a_decimal_part;
	std::string b_int_part, b_decimal_part;
	if (a_dot_num != -1)
	{
		a_int_part.assign(a, 0, a_dot_num);
//		std::cout << a_int_part << std::endl;
		a_decimal_part.assign(a, a_dot_num + 1, a_length - a_dot_num);
//		std::cout << a_decimal_part << std::endl;
	}
	else  //just integers to add
	{
		a_int_part = a;
		a_decimal_part = "0";
	}
	if (b_dot_num != -1)
	{
		b_int_part.assign(b, 0, b_dot_num);
		b_decimal_part.assign(b, b_dot_num + 1, b_length - b_dot_num);
		//	std::cout << b_int_part << std::endl;
		//	std::cout << b_decimal_part << std::endl;
	}
	else
	{
		b_int_part = b;
		b_decimal_part = "0";
	}
	//to do: first to add the decimal part and then int part
	bool between_int_decimal = 0;
	int a_decimal_length = a_decimal_part.length();
	int b_decimal_length = b_decimal_part.length();
	
	if (a_decimal_length > b_decimal_length)
	{
		bool between = 0;
		std::string sum(a_decimal_part);
		for (int i = a_decimal_length - 1; i >= 0; --i)
		{
			int sum_temp = 0;
			if (i >= b_decimal_length)
			{
				sum.at(i) += between;
				sum_temp = sum.at(i) - 48;  //change char into int
			}
			else
			{
				sum.at(i) += b_decimal_part.at(i) + between; 
				sum_temp = sum.at(i) - 48 * 2;
			}
			between = 0;
			if(sum_temp > 9)
			{
				between = 1;
				sum_temp -= 10;
			}
			sum.at(i) = sum_temp + 48;
			if (i == 0)
			{
				between_int_decimal = between;
			}
		}
		sum_decimal = sum;
	}
	else
	{
		bool between = 0;
		std::string sum(b_decimal_part);
		for (int i = b_decimal_length - 1; i >= 0; --i)
		{
			int sum_temp = 0;
			if (i >= a_decimal_length)
			{
				sum.at(i) += between;
				sum_temp = sum.at(i) - 48;  //change char into int
			}
			else
			{
				sum.at(i) += a_decimal_part.at(i) + between;
				sum_temp = sum.at(i) - 48 * 2;
			}
			if (sum_temp > 9)
			{
				between = 1;
				sum_temp -= 10;
			}
			else
			{
				between = 0;
			}
			sum.at(i) = sum_temp + 48;
			if (i == 0)
			{
				between_int_decimal = between;
			}
		}
		sum_decimal = sum;
	}
	//to do: add the integer part
	int a_int_length = a_int_part.length();
	int b_int_length = b_int_part.length();
	if (a_int_length > b_int_length)
	{
		bool between = 0;
		std::string sum(a_int_part);
		for (int i = a_int_length - 1; i >= 0; --i)
		{
			int sum_temp = 0;
			if (i == a_int_length - 1)
			{
				sum.at(i) += between_int_decimal;
			}
			if (i >= a_int_length - b_int_length)
			{
				sum.at(i) += b_int_part.at(i - (a_int_length - b_int_length)) + between;
				sum_temp = sum.at(i) - 48 * 2;
			}
			else
			{
				sum.at(i) += between;
				sum_temp = sum.at(i) - 48;
			}
			if (sum_temp > 9)
			{
				between = 1;
				sum_temp -= 10;
			}
			else
			{
				between = 0;
			}
			sum.at(i) = sum_temp + 48;
		}
		if (between)
		{
			sum_int = '1' + sum;
		}
		else
		{
			sum_int = sum;
		}
	}
	else
	{
		bool between = 0;
		std::string sum(b_int_part);
		for (int i = b_int_length - 1; i >= 0; --i)
		{
			int sum_temp = 0;
			if (i == b_int_length - 1)
			{
				sum.at(i) += between_int_decimal;
			}
			if (i >= b_int_length - a_int_length)
			{
				sum.at(i) += a_int_part.at(i - (b_int_length - a_int_length)) + between;
				sum_temp = sum.at(i) - 48 * 2;
			}
			else
			{
				sum.at(i) += between;
				sum_temp = sum.at(i) - 48;
			}
			if (sum_temp > 9)
			{
				between = 1;
				sum_temp -= 10;
			}
			else
			{
				between = 0;
			}
			sum.at(i) = sum_temp + 48;
		}
		if (between)
		{
			sum_int = '1' + sum;
		}
		else
		{
			sum_int = sum;
		}
	}
	sum = sum_int + '.' + sum_decimal;
	return sum;
}
std::string multiply(std::string a, std::string b)
{
	std::string dot,dot_int,dot_decimal;
	std::string b_decimal("0");
	dot_int = "0";
	dot_decimal = "0";
	size_t int_b = atoi(b.c_str());
	int dot_num = b.find_first_of('.');
	int move_bits = 0;
	if (dot_num != -1)
	{
		b_decimal.assign(b, dot_num + 1, b.length() - dot_num);
		move_bits = b_decimal.length();
	}
	else
	{

	}
	size_t decimal_b = atoi(b_decimal.c_str());
//	std::cout << int_b << std::endl;
//	std::cout << decimal_b << std::endl;
	if (int_b == 0)
	{
		dot_int = '0';
	}
	for (size_t i = 0; i < int_b; ++i)  //6ms
	{
		dot_int = add(dot_int, a);
	}
//	std::cout << dot_int << std::endl;
	// to do: optimize the time cost
	if (decimal_b <= 99)
	{
		for (size_t i = 0; i < decimal_b; ++i)  //60ms ~ 160ms
		{
			dot_decimal = add(dot_decimal, a);
		}
	}
	else
	{
		std::string dot_decimal_1("0");
		std::string dot_decimal_2("0");
		size_t decimal_b_hundred = decimal_b / 100;
		size_t decimal_b_decade = decimal_b % 100;
//		std::cout << decimal_b_hundred << std::endl;
//		std::cout << decimal_b_decade << std::endl;
		for (size_t i = 0; i < decimal_b_decade; ++i)
		{
			dot_decimal_1 = add(dot_decimal_1, a);
		}
		for (size_t i = 0; i < decimal_b_hundred; ++i)
		{
			dot_decimal_2 = add(dot_decimal_2, a);
		}
		int position_of_point = dot_decimal_2.find_first_of('.');
		if (position_of_point == -1)  // when a is a integer
		{
			dot_decimal_2.append("00");
		}
		else
		{
			dot_decimal_2.erase(position_of_point,1);
			dot_decimal_2.insert(position_of_point + 2, ".");
		}
		dot_decimal = add(dot_decimal_1, dot_decimal_2);
//		std::cout << dot_decimal << std::endl;
	}
	int former_dot_num = dot_decimal.find_first_of('.');
//	std::cout << dot_decimal << std::endl;
	if (former_dot_num != -1)
	{
		dot_decimal.erase(former_dot_num, 1);
		//	std::cout << dot_decimal << std::endl;
	}
	int latter_dot_num = former_dot_num - move_bits;
	if (latter_dot_num >= 0)
	{
		dot_decimal.insert(latter_dot_num, 1, '.');
	}
	else
	{
		dot_decimal.insert(0, -latter_dot_num, '0');
		dot_decimal.insert(0, 1, '.');
	}
//	std::cout << dot_decimal << std::endl;
	dot = add(dot_int, dot_decimal);  //1.522756
	return dot;
}
int main()
{
	std::string s;
	int n;
//	s = add("148.08", "4.1956");
//	s = multiply("0.0009", "0.001");
//	std::cout << s << std::endl;
	while (std::cin >> s >> n) 
	{
		if (n == 0)
		{
			std::cout << '1' << std::endl;
			continue;
		}
		if(atof(s.c_str()) < 0.00000000001)  //treat a too small number as 0  
		{
			std::cout << '0' << std::endl;
			continue;
		}
		std::string sum(s);
		for (int i = 0; i < n - 1; ++i)
		{
			sum = multiply(sum, s);
		}
		
		//to do: erase the unnecessary '0'
		for (int i = 0; i < sum.length(); ++i)
		{
			if (sum.at(i) == '0')
			{
				sum.erase(i,1);
				--i;
			}
			else
			{
				break;
			}
		}
		if (sum.find_first_of('.') != -1)
		{
			for (int i = sum.length() - 1; i >= 0; --i)
			{
				if (sum.at(i) == '0')
				{
					sum.erase(i, 1);
				}
				else if (sum.at(i) == '.')
				{
					sum.erase(i, 1);
					break;
				}
				else
				{
					break;
				}
			}
		}
		std::cout << sum << std::endl;
	}
	return 0;
}