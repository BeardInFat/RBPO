#include <cmath>
#include <ostream>
//variant 22 Chudakov, individual zadanie 22-15=7
export module Math;

export namespace Math
{
	class Complex
	{
	private:
		double c_mod;
		double c_arg;
	public:
		Complex(): c_mod(0), c_arg(0) {}
		Complex(double a): c_mod(abs(a)), c_arg(0) {}
		Complex(double re, double im)
		{
			c_arg = atan2(im, re);
			c_mod = sqrt(re * re + im * im);
		}
		
		static Complex FromExponentialForm(double mod, double arg)
		{
			double re = mod * cos(arg);
			double im = mod * sin(arg);
			return Complex(re, im);
		}
		static Complex FromAlgebraicForm(double re, double im)
		{
			return Complex(re, im);
		}

		double Re()
		{
			return this->c_mod * cos(c_arg);
		}
		double Im()
		{
			return this->c_mod * sin(c_arg);
		}
		double Mod()
		{
			return this->c_mod;
		}
		double Arg()
		{
			return this->c_arg;
		}

		explicit operator double(){ return Mod(); }
		Complex operator-()
		{
			return Complex(-this->Re(),-this->Im());
		}
		Complex& operator++() // ���������� ���������
		{
			double re = this->Re()+1;
			double im = this->Im();
			this->c_mod = sqrt(re * re + im * im);
			this->c_arg = atan2(im, re);
			return *this;
		}
		const Complex operator++(int) // ����������� ���������
		{
			Complex it(*this);
			double re = this->Re() + 1;
			double im = this->Im();
			this->c_mod = sqrt(re * re + im * im);
			this->c_arg = atan2(im, re);
			return it;
		}
		Complex& operator--() // ���������� ���������
		{
			double re = this->Re() - 1;
			double im = this->Im();
			this->c_mod = sqrt(re * re + im * im);
			this->c_arg = atan2(im, re);
			return *this;
		}
		const Complex operator--(int) // ����������� ���������
		{
			Complex it(*this);
			double re = this->Re() - 1;
			double im = this->Im();
			this->c_mod = sqrt(re * re + im * im);
			this->c_arg = atan2(im, re);
			return it;
		}
		Complex& operator+=(Complex chs)
		{
			double re = this->Re() + chs.Re();
			double im = this->Im() + chs.Im();
			this->c_mod = sqrt(re * re + im * im);
			this->c_arg = atan2(im, re);
			return *this;
		}
		Complex& operator-=(Complex chs)
		{
			double re = this->Re() - chs.Re();
			double im = this->Im() - chs.Im();
			this->c_mod = sqrt(re * re + im * im);
			this->c_arg = atan2(im, re);
			return *this;
		}
		// compl1 * compl2 = r1*r2( cos(arg1+arg2) + i*sin(arg1+arg2) )
		Complex& operator*=(Complex chs)
		{
			this->c_mod = this->Mod() * chs.Mod();
			this->c_arg = this->Arg() + chs.Arg();
			return *this;
		}
		// compl1 / compl2 = r1/r2 *( cos(arg1-arg2) + i*sin(arg1-arg2) )
		Complex& operator/=(Complex chs)
		{
			this->c_mod = this->Mod() / chs.Mod();
			this->c_arg = this->Arg() - chs.Arg();
			return *this;
		}
	};

	Complex operator+(Complex a, Complex b)
	{
		double re = a.Re() + b.Re();
		double im = a.Im() + b.Im();
		return Complex(re, im);
	}
	Complex operator-(Complex a, Complex b)
	{
		double re = a.Re() - b.Re();
		double im = a.Im() - b.Im();

		return Complex(re, im);
	}
	Complex operator*(Complex a, Complex b)
	{
		double re = a.Re() * b.Re() - a.Im() * b.Im();
		double im = a.Re() * b.Im() + a.Im() * b.Re();
		return Complex(re, im);
	}
	Complex operator/(Complex a, Complex b)
	{
		double re = (a.Re() * b.Re() + a.Im() * b.Im()) / (b.Re() * b.Re() + b.Im() * b.Im());
		double im = (a.Im() * b.Re() - a.Re() * b.Im()) / (b.Re() * b.Re() + b.Im() * b.Im());
		return Complex(re, im);
	}

	Complex operator""i(long double im) { return Complex(0, im); }
	Complex operator""i(unsigned long long im) { return Complex(0, im); }

	std::ostream& operator<< (std::ostream& os, Complex complex)
	{
		if (complex.Im() >= 0) {
			return os << complex.Re() << "+" << complex.Im() << "i";
		}
		return os << complex.Re() << complex.Im() << "i";
	}


	int FindGreatestCommonDivisor(int a, int b)
	{
		if (a < b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		int i;
		while (b != 0)
		{
			i = a % b;
			a = b;
			b = i;
		}
		return abs(a);
	}
	int FindLeastCommonMultiple(int x, int y) {
		return abs(x * y) / FindGreatestCommonDivisor(x, y);
	}



	class Rational
	{
	private:
		int nom;
		int denom;
		void Sokr()
		{
			int nod = FindGreatestCommonDivisor(nom, denom);
			nom /= nod;
			denom /= nod;
			if (denom < 0)
			{
				nom = -nom;
				denom = -denom;
			}
		}
	public:
		Rational() :nom(0), denom(1) {}
		Rational(int a) :nom(a), denom(1) {}
		Rational(int a, int b)
		{
			nom = a;
			denom = b;
			Sokr();
		}

		int Nominator() { return nom; }
		int Denominator() { return denom; }

		explicit operator double() { return (double)this->nom / this->denom; }

		Rational operator-()
		{
			return Rational(-this->nom, this->denom);
		}
		Rational& operator++()
		{
			this->nom += this->denom;
			return *this;
		}
		Rational operator++(int)
		{
			Rational it(*this);
			it.nom += it.denom;
			return it;
		}
		Rational& operator--()
		{
			this->nom -= this->denom;
			return *this;
		}
		Rational operator--(int)
		{
			Rational it(*this);
			it.nom -= it.denom;
			return it;
		}

		Rational& operator+=(Rational x)
		{
			this->nom = this->nom * x.denom + x.nom * this->denom;
			this->denom = this->denom * x.denom;
			this->Sokr();
			return *this;
		}
		Rational& operator-=(Rational x)
		{
			this->nom = this->nom * x.denom - x.nom * this->denom;
			this->denom = this->denom * x.denom;
			this->Sokr();
			return *this;
		}
		Rational& operator*=(Rational x)
		{
			this->nom = this->nom * x.nom;
			this->denom = this->denom * x.denom;
			this->Sokr();
			return *this;
		}
		Rational& operator/=(Rational x)
		{
			this->nom = this->nom * x.denom;
			this->denom = this->denom * x.nom;
			this->Sokr();
			return *this;
		}
	};

	Rational operator+(Rational a, Rational b)
	{
		int nom = a.Nominator() * b.Denominator() + b.Nominator() * a.Denominator();
		int denom = a.Denominator() * b.Denominator();
		return Rational(nom, denom);
	}
	Rational operator-(Rational a, Rational b)
	{
		int nom = a.Nominator() * b.Denominator() - b.Nominator() * a.Denominator();
		int denom = a.Denominator() * b.Denominator();
		return Rational(nom, denom);
	}
	Rational operator*(Rational a, Rational b)
	{
		int nom = a.Nominator() * b.Nominator();
		int denom = a.Denominator() * b.Denominator();
		return Rational(nom, denom);
	}
	Rational operator/(Rational a, Rational b)
	{
		int nom = a.Nominator() * b.Denominator();
		int denom = a.Denominator() * b.Nominator();
		return Rational(nom, denom);
	}

	bool operator== (Rational a, Rational b)
	{
		if (a.Nominator() == b.Nominator() && a.Denominator() == b.Denominator())
			return true;
		else
			return false;
	}

	bool operator< (Rational a, Rational b)
	{
		return (double)a < (double)b;
	}
	bool operator> (Rational a, Rational b)
	{
		return (double)a > (double)b;
	}
	bool operator>= (Rational a, Rational b)
	{
		return (double)a >= (double)b;
	}

	bool operator<= (Rational a, Rational b)
	{
		return (double)a <= (double)b;
	}


	std::ostream& operator<< (std::ostream& os, Rational rational)
	{
		return os << rational.Nominator() << "/" << rational.Denominator();
	}

	Complex f(const Complex& z)
	{
		Complex a = 2 + 0i;
		Complex func = a * z + exp(5) * (1 + z);
		return func;
	}
	Rational f(const Rational& r)
	{
		Rational a = 2 / 1;
		Rational func = a * r + exp(5) * (1 + r);
		return func;
	}
	double f(double x)
	{
		double a = 2.0;
		double func = a * x + exp(5) * (1 + x);
		return func;
	}
}