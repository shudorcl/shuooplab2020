#include "vector.h"
#include <cmath>
#include <iostream>
using namespace std;

Vector::Vector(int vdim)
    : nums(new double(vdim)), size(vdim)
{
    //分配内存
    //初始化，并记录size
    for (int i = 0; i < vdim; i++)
        nums[i] = 0;
}
Vector::Vector(int vdim, double prim)
    : nums(new double(vdim)), size(vdim)
{
    for (int i = 0; i < vdim; i++)
        nums[i] = prim;
}
Vector::Vector(const Vector &ov)
{
    nums = new double(ov.size);
    //赋值，并记录size
    for (int i = 0; i < ov.size; i++)
        nums[i] = ov.nums[i];
    size = ov.size;
}

Vector::~Vector()
{
    if (nums)
        delete[] nums;
    nums = NULL;
    cout << "Destruction Susseed!" << endl;
}
double Vector::Modular() const
{
    double sum;
    for (int i = 0; i < size; i++)
    {
        sum += pow((nums[i]), 2);
    }
    return sqrt(sum);
}
void Vector::Normalize()
{
    double mod;
    for (int i = 0; i < size; i++)
    {
        mod += pow((this->nums[i]), 2);
    }
    mod = sqrt(mod);
    for (int i = 0; i < size; i++)
    {
        this->nums[i] /= mod;
    }
}
void Vector::Show() const
{
    cout << '[';
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
            cout << nums[i] << ',';
        else
            cout << nums[i] << ']' << endl;
    }
}
Vector &Vector::operator=(const Vector &ov)
{
    //检测输入是否为自身以防资源丢失
    if (&ov == this)
        return *this;

    //先删除自身资源，再申请新资源
    if (this->nums)
        delete[] nums;
    this->nums = new double(ov.size);

    //赋值，并记录size
    for (int i = 0; i < ov.size; i++)
    {
        this->nums[i] = ov.nums[i];
    }
    this->size = ov.size;

    return *this;
}
double Vector::index(int index)
{
    //异常处理
    if (index < 0 || index >= this->size)
    {
        //throw e();
    }
    return this->nums[index];
}
double Vector::pop(int index)
{
    //处理空向量情况
    if (this->nums == NULL)
    {
        cout << "This is a empty Vector!" << endl;
        return 0;
    }

    //先储存要返回的成员
    double last = this->nums[this->size - 1];

    //再申请内存空间
    double *new_nums = new double(this->size - 1);

    //拷贝数据
    for (int i = 0; i < this->size - 1; i++)
    {
        new_nums[i] = this->nums[i];
    }
    //指向新内存空间，内存拷贝，再删除new_nums
    delete[] nums;
    nums = new double(this->size - 1);
    memcpy(nums, new_nums, this->size);
    delete[] new_nums;

    //最后更新size
    this->size--;

    return last;
}

void Vector::append(double new_double)
{
    //申请新空间
    double *new_nums = new double(this->size + 1);

    //拷贝数据
    for (int i = 0; i < this->size; i++)
    {
        new_nums[i] = this->nums[i];
    }
    new_nums[this->size] = new_double;

    //指向新内存空间，内存拷贝，再删除new_nums
    delete[] nums;
    nums = new double(this->size + 1);
    memcpy(nums, new_nums, this->size);
    delete[] new_nums;

    //最后更新size
    this->size++;
}

//在指定位置插入成员
void Vector::insert(int index, double new_double)
{
    //申请新空间
    double *new_nums = new double(this->size + 1);

    //和append方法没有本质不同，只需要改变拷贝顺序
    for (int i = 0; i < index; i++)
    {
        new_nums[i] = this->nums[i];
    }
    new_nums[index] = new_double;
    for (int i = index; i < this->size; i++)
    {
        new_nums[i + 1] = this->nums[i];
    }

    //指向新内存空间，内存拷贝，再删除new_nums
    delete[] nums;
    nums = new double(this->size + 1);
    memcpy(nums, new_nums, this->size);
    delete[] new_nums;

    //最后更新size
    this->size++;
}
/*Vector Vector::chip(int start, int end, int step)
{
    //设计成产生一个临时变量赋值时使用
    Vector tmp((end - start) / step);
    for (int j = start; j < end; j += step)
    {
        tmp.nums[j] = nums[j];
    }
    return tmp;
}*/

//重载运算符
    Vector Vector::operator+(Vector &ov)
    {
        if (this->size != ov.size)
        {
            //throw e();
        }

        Vector temp(this->size);
        for (int i = 0; i < this->size; i++)
        {
            temp.nums[i] = this->nums[i] + ov.nums[i];
        }
        return temp;
    }

    Vector Vector::operator-(Vector &ov)
    {
        if (this->size != ov.size)
        {
            //throw e();
        }

        Vector temp(this->size);
        for (int i = 0; i < this->size; i++)
        {
            temp.nums[i] = this->nums[i] - ov.nums[i];
        }
        return temp;
    }

    Vector &Vector::operator+=(Vector &ov)
    {
        if (this->size != ov.size)
        {
            //throw e();
        }
        *this = *this + ov;
        return *this;
    }
    bool Vector::operator!=(Vector &ov)
    {
        if (this->size != ov.size)
        {
            return true;
        }

        for (int i; i < size; i++)
        {
            if (this->nums[i] != ov.nums[i])
            {
                return true;
            }
        }
        return false;
    }

    ostream &operator<<(ostream &out, const Vector &ov)
    {
        for (int i; i < ov.size; i++)
        {
            out << ov.nums[i];
        }
        return out;
    }
    istream &operator>>(istream &in, Vector &ov)
    {
        //我也不太会
    }

    bool Vector::operator==(Vector &ov)
    {
        if (this->size != ov.size)
        {
            return false;
        }

        for (int i; i < size; i++)
        {
            if (this->nums[i] != ov.nums[i])
            {
                return false;
            }
        }
        return true;
    }
    double Vector::operator*(Vector &ov)
    {
        if (this->size != ov.size)
        {
            //throw e();
        }

        double sum = 0;
        for (int i = 0; i < this->size; i++)
        {
            sum += this->nums[i] * ov.nums[i];
        }
        return sum;
    }

    Vector Vector::operator*(double mult)
    {
        Vector temp(this->size);
        for (int i = 0; i < this->size; i++)
        {
            temp.nums[i] = this->nums[i] * mult;
        }
        return temp;
    }

    double Vector::operator[](int index)
    {
        //异常处理
        if (index < 0 || index >= this->size)
        {
            //throw e();
        }
        return this->nums[index];
    }
