//用于运行
//#define MAIN_CPP
#ifdef MAIN_CPP
#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::size_t;
using std::max;
using std::swap;


//大整数
class BigUnsignedInteger
{
private:
	vector<unsigned char> nums;//0是最低位 小端法存储 100进制村
public:
	//计算组合数A(n,k)
	static BigUnsignedInteger caculate_combanation_num(unsigned n, unsigned k);
	static int compare(const BigUnsignedInteger& integer1, const BigUnsignedInteger& integer2);//大于1 等于0 小于-1
	static BigUnsignedInteger &mutiply_unsigned_char(BigUnsignedInteger& integer, unsigned u_char);//乘以一个unsigned char
public:
	explicit BigUnsignedInteger();
	explicit BigUnsignedInteger(unsigned num);
	explicit BigUnsignedInteger(const char *num_str); //有时间实现一下

													  //比较
	bool operator<(const BigUnsignedInteger& integer) const { return compare(*this, integer) < 0; }
	bool operator==(const BigUnsignedInteger& integer) const { return compare(*this, integer) == 0; }
	bool operator>(const BigUnsignedInteger& integer) const { return compare(*this, integer) > 0; }
	bool operator<=(const BigUnsignedInteger& integer) const { return compare(*this, integer) <= 0; }
	bool operator>=(const BigUnsignedInteger& integer) const { return compare(*this, integer) >= 0; }
	bool operator!=(const BigUnsignedInteger& integer) const { return compare(*this, integer) != 0; }
	bool operator!=(const unsigned& integer) const { return compare(*this, BigUnsignedInteger(integer)) != 0; };
	//置零
	void set_zero();
	//加法运算
	BigUnsignedInteger operator+(const BigUnsignedInteger& add_integer);
	BigUnsignedInteger& operator+=(const BigUnsignedInteger& add_integer);
	//用于输出
	string to_string();

};

char num_str1[1004];//第一个数字
char num_str2[1004];//第二个数字
string result_str;
unsigned test_case_num;
int main()
{
	scanf("%u", &test_case_num);
	for(unsigned i=0;i<test_case_num;i++)
	{
		scanf("%s", num_str1);
		scanf("%s", num_str2);
		BigUnsignedInteger integer1(num_str1);
		BigUnsignedInteger integer2(num_str2);
		integer1 += integer2;
		result_str = integer1.to_string();
		printf("%s\n", result_str.c_str());
	}
	return 0;
}



BigUnsignedInteger & BigUnsignedInteger::mutiply_unsigned_char(BigUnsignedInteger & integer, unsigned u_char)
{
	vector<unsigned char> &nums = integer.nums;
	if (u_char == 0)
	{
		nums.clear();
		return integer;
	}
	size_t integer_length = nums.size();
	unsigned temp_value = 0;//临时存储的值
	for (size_t i = 0; i<integer_length; i++)
	{
		temp_value += nums[i] * u_char;
		nums[i] = static_cast<unsigned char>(temp_value % 100);
		temp_value /= 100;
	}
	while (temp_value != 0)//处理最后的进位
	{
		nums.push_back(static_cast<unsigned char>(temp_value % 100));
		temp_value /= 100;
	}
	return integer;
}

BigUnsignedInteger BigUnsignedInteger::caculate_combanation_num(unsigned n, unsigned k)
{
	BigUnsignedInteger combanation_num(1);
	for (unsigned i = 0; i < k; i++)
		mutiply_unsigned_char(combanation_num, n - i);
	return combanation_num;
}

int BigUnsignedInteger::compare(const BigUnsignedInteger & integer1, const BigUnsignedInteger & integer2)
{
	const vector<unsigned char> &nums1 = integer1.nums;
	const vector<unsigned char> &nums2 = integer2.nums;
	size_t length1 = nums1.size();
	size_t length2 = nums2.size();
	if (length1 != length2) return length1 - length2;
	else if (length1 == 0) return 0;
	else
	{
		for (size_t i = length1 - 1; i > 0; i--)
			if (nums1[i] != nums2[i]) return nums1[i] - nums2[i];
		return nums1[0] - nums2[0];
	}
}

BigUnsignedInteger::BigUnsignedInteger()
{
}

BigUnsignedInteger::BigUnsignedInteger(unsigned num)
{
	while (num > 0)
	{
		nums.push_back(static_cast<unsigned char>(num % 100));
		num /= 100;
	}
}

BigUnsignedInteger::BigUnsignedInteger(const char * num_str)
{
	if (num_str[0] != '\0' && num_str[0] != '0')
	{
		unsigned char_length = strlen(num_str), num_length = char_length / 2, start_index = 0;
		if (char_length % 2)//如果是奇数
		{
			nums.resize(num_length + 1);
			nums[num_length] = num_str[0] - '0';
			start_index = 1;
		}
		else nums.resize(num_length);
		while (start_index < char_length)
		{
			nums[--num_length] = (num_str[start_index] - '0') * 10 + (num_str[start_index + 1] - '0');
			start_index += 2;
		}
	}

}

void BigUnsignedInteger::set_zero()
{
	nums.clear();
}

BigUnsignedInteger BigUnsignedInteger::operator+(const BigUnsignedInteger & add_integer)
{
	BigUnsignedInteger result;
	size_t self_length = nums.size(), add_length = add_integer.nums.size();
	//修改长度
	result.nums.resize(max(self_length, add_length));

	unsigned temp_value = 0;//临时存储的值
	const vector<unsigned char> &self_nums = nums;
	const vector<unsigned char> &add_nums = add_integer.nums;
	vector<unsigned char> &result_nums = result.nums;

	size_t i = 0, j = 0;
	while (i < self_length && j < add_length)
	{
		temp_value += self_nums[i] + add_nums[j];
		result_nums[i] = static_cast<unsigned char>(temp_value % 100);
		temp_value /= 100;
		++i;
		++j;
	}
	while (i < self_length)
	{
		temp_value += self_nums[i];
		result_nums[i] = static_cast<unsigned char>(temp_value % 100);
		temp_value /= 100;
		++i;
	}
	while (j < add_length)
	{
		temp_value += add_nums[j];
		result_nums[j] = static_cast<unsigned char>(temp_value % 100);
		temp_value /= 100;
		++j;
	}
	if (temp_value != 0)//处理最后的进位
		result_nums.push_back(static_cast<unsigned char>(temp_value % 100));

	return result;
}

BigUnsignedInteger& BigUnsignedInteger::operator+=(const BigUnsignedInteger & add_integer)
{
	size_t self_length = nums.size(), add_length = add_integer.nums.size();
	//修改长度
	nums.resize(max(self_length, add_length));

	unsigned temp_value = 0;//临时存储的值
	const vector<unsigned char> &add_nums = add_integer.nums;

	size_t i = 0, j = 0;
	while (i < self_length && j < add_length)
	{
		temp_value += nums[i] + add_nums[j];
		nums[i] = static_cast<unsigned char>(temp_value % 100);
		temp_value /= 100;
		++i;
		++j;
	}
	while (i < self_length)
	{
		temp_value += nums[i];
		nums[i] = static_cast<unsigned char>(temp_value % 100);
		temp_value /= 100;
		++i;
	}
	while (j < add_length)
	{
		temp_value += add_nums[j];
		nums[j] = static_cast<unsigned char>(temp_value % 100);
		temp_value /= 100;
		++j;
	}
	if (temp_value != 0)//处理最后的进位
		nums.push_back(static_cast<unsigned char>(temp_value % 100));
	return *this;
}


string BigUnsignedInteger::to_string()
{

	size_t nums_length = nums.size();
	if (nums_length == 0)return string("0");
	string result;
	for (size_t i = 0; i < nums_length - 1; i++)
	{
		result.push_back(static_cast<char>('0' + (nums[i] % 10)));
		result.push_back(static_cast<char>('0' + (nums[i] / 10)));
	}
	//最后一位
	result.push_back(static_cast<char>('0' + (nums[nums_length - 1] % 10)));
	char high_num = nums[nums_length - 1] / 10;
	if (high_num != 0)
		result.push_back(static_cast<char>('0' + high_num));
	//反转一下
	size_t result_length = result.size();
	for (size_t i = 0; i < result_length / 2; i++)
		swap(result[i], result[result_length - i - 1]);
	return result;
}

#endif
