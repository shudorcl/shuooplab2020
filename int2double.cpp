#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

class Vector
{
public:
    //指定向量维数，成员初始化为0
    Vector(int vdim)
    {
        //分配内存
        this->nums = new double(vdim);
        //初始化，并记录size
        for (int i = 0; i < vdim; i++)
        {
            this->nums[i] = 0;
        }
        this->size = vdim;
    }

    //指定向量维数和初始值
    Vector(int vdim, double prim)
    {
        //分配内存
        this->nums = new double(vdim);
        //初始化，并记录size
        for (int i = 0; i < vdim; i++)
        {
            this->nums[i] = prim;
        }
        this->size = vdim;
    }

    //向量复制
    Vector &operator=(Vector &ov)
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

    //深拷贝构造函数,好像和上面差不多啊，你们看看
    Vector(Vector &ov)
    {
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
    }
    virtual ~Vector()
    {
        //删除资源
        if (this->nums)
            delete[] nums;
    }

    //求模
    double modular()
    {
        double sum;
        for (int i = 0; i < size; i++)
        {
            sum += pow((this->nums[i]), 2);
        }
        return sqrt(sum);
    }

    //显示
    void show()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << this->nums[i] << endl;
        }
    }

    //转换为单位向量
    void normalize()
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

    //向量前后转置
    void Transposition()
    {
        //若为空数组直接返回
        if (this->nums == NULL)
            return;

        //先申请内存空间
        double *new_nums = new double(this->size);
        //反着拷贝数据
        for (int i = 0; i < this->size; i++)
        {
            new_nums[i] = this->nums[this->size - i - 1];
        }
        //指向新内存空间，内存拷贝，再删除new_nums
        delete[] nums;
        nums = new double(this->size);
        memcpy(nums, new_nums, this->size);
        delete[] new_nums;
    }

    //获得指定位置成员,默认第一个
    double index(int index = 0)
    {
        //异常处理
        if (index < 0 || index >= this->size)
        {
            //throw e();
        }
        return this->nums[index];
    }

    //获取一个成员并弹出,默认最后一个
    double pop(int index = -1)
    {
        //处理空向量情况
        if (this->nums == NULL)
        {
            cout << "This is a empty Vector!" << endl;
            return NULL;
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

    //在末尾加上成员
    void append(double new_double)
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
    void insert(int index, double new_double)
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

    //获得指定部分和步长的切片,默认全部，步长默认为1
    Vector chip(int start, int end, int step)
    {
        //不太会
    }
    //获得向量维数
    int Getlen()
    {
        return this->size;
    }

    //重载运算符
    Vector &operator+(Vector &ov)
    {
        if (this->size != ov.size)
        {
            //throw e();
        }

        Vector temp = Vector(this->size);
        for (int i = 0; i < this->size; i++)
        {
            temp.nums[i] = this->nums[i] + ov.nums[i];
        }
        return temp;
    }

    Vector &operator-(Vector &ov)
    {
        if (this->size != ov.size)
        {
            //throw e();
        }

        Vector temp = Vector(this->size);
        for (int i = 0; i < this->size; i++)
        {
            temp.nums[i] = this->nums[i] - ov.nums[i];
        }
        return temp;
    }

    void operator+=(Vector &ov)
    {
        if (this->size != ov.size)
        {
            //throw e();
        }

        for (int i; i < this->size; i++)
        {
            this->nums[i] += ov.nums[i];
        }
    }
    bool operator!=(Vector &ov)
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

    friend ostream &operator<<(ostream &out, const Vector &ov)
    {
        for (int i; i < ov.size; i++)
        {
            out << ov.nums[i];
        }
        return out;
    }
    friend istream &operator>>(istream &in, Vector &ov)
    {
        //我也不太会
    }

    bool operator==(Vector &ov)
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
    double operator*(Vector &ov)
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

    Vector operator*(double mult)
    {
        Vector temp = Vector(this->size);
        for (int i = 0; i < this->size; i++)
        {
            temp.nums[i] = this->nums[i] * mult;
        }
        return temp;
    }

    double operator[](int index)
    {
        //异常处理
        if (index < 0 || index >= this->size)
        {
            //throw e();
        }
        return this->nums[index];
    }

private:
    double *nums;
    int size;
};

int main()
{
}
