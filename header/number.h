#pragma once

#include<stdio.h>


class ratio
{
private:
    int denominator; // 분모
    int numerator; // 분자

public:
    //생성자입니다.
    ratio()
    {
        denominator = 1;
        numerator = 0;
    }

    ratio(int n, int d)
    {
        denominator = d;
        numerator = n;
    }

    //소멸자 입니다.
    ~ratio() = default;

    void set_denominator(int a)
    {
        if (a != 0)
            denominator = a;
        else
            printf(">> class: ratio > set_denominator() | numerator is 0");
    }

    void set_numerator(int a)
    {
        numerator = a;
        denominator = 1;
    }

    //double로 반환하기
    double get_double()
    {
        double res;
        res = (double)numerator / (double)denominator;

        return res;
    }

    // 약분하기
    void reduction()
    {
        for (int i = ((numerator < denominator) ? numerator : denominator); i > 1; i--)
        {
            if (denominator % i == 0 && numerator % i == 0)
            {
                denominator = denominator / i;
                numerator = numerator / i;
            }
        }
    }

    // 역수취하기
    ratio reciprocal()
    {
        ratio res;
        int temp;

        if (this->numerator != 0)
        {
            temp = this->denominator;
            this->denominator = this->numerator;
            this->numerator = temp;
            res.denominator = this->denominator;
            res.numerator = this->numerator;
        }
        else
            printf(">> class: ratio > reciprocal() | numerator is 0");

        return res;
    }

    // 출력하기
    char* get_string()
    {
        char output[250];
        sprintf(output, "%d / %d", this->numerator, this->denominator);
        return output;
    }

    ratio operator + (ratio& c)
    {
        ratio result;
        result.denominator = c.denominator * this->denominator;
        result.numerator = c.denominator * this->numerator + c.numerator * this->denominator;

        if (result.denominator == 0)
            printf(">> class: ratio > operator + (ratio) | divide by 0\n");

        result.reduction();
        return result;
    }

    ratio operator - (ratio& c)
    {
        ratio result;
        result.denominator = c.denominator * this->denominator;
        result.numerator = c.denominator * this->numerator - c.numerator * this->denominator;

        if (result.denominator == 0)
            printf(">> class: ratio > operator - (ratio) | divide by 0\n");

        result.reduction();
        return result;
    }

    ratio operator * (ratio& c)
    {
        ratio result;
        result.denominator = c.denominator * this->denominator;
        result.numerator = c.numerator * this->numerator;

        if (result.denominator == 0)
            printf(">> class: ratio > operator * (ratio) | divide by 0\n");

        result.reduction();
        return result;
    }

    ratio operator / (ratio& c)
    {
        ratio result;
        result.numerator = c.denominator * this->numerator;
        result.denominator = c.numerator * this->denominator;

        if (result.denominator == 0)
            printf(">> class: ratio > operator / (ratio) | divide by 0\n");

        result.reduction();
        return result;
    }

};
