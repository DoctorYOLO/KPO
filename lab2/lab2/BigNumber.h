#include <vector>

namespace BigNumber
{
	class CMegaNumber
	{
	public:
		CMegaNumber();
		CMegaNumber(int count);

		std::vector<int> GetNumber() const;
		void SetNumber(std::vector<int> const &number);
		size_t length() const;
		CMegaNumber const ReverseMegaNumber(CMegaNumber &megNumber) const;
		std::string ToString();
		void Erase(int index);

		CMegaNumber const operator =(std::vector<int> const &number);
		CMegaNumber const operator =(CMegaNumber const &number);

		CMegaNumber const operator +(CMegaNumber const &number) const;
		CMegaNumber const operator -(CMegaNumber const &number) const;
		CMegaNumber const operator *(CMegaNumber const &number) const;
		CMegaNumber const operator *(int number) const;
		CMegaNumber const operator /(CMegaNumber const &number) const;

		int &operator [](int ind);
		void const operator +=(int number);

	private:
		void Minus(std::vector<int> &number1, std::vector<int> &number2, CMegaNumber &answer, int len) const;
		int ComparNumber(CMegaNumber &number1, CMegaNumber &number2) const;
		int GetMaxPossibleNumber(CMegaNumber &number1, CMegaNumber &number2) const;

		std::vector<int> m_number;
	};
}
