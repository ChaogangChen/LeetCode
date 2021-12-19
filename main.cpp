#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
using namespace std;
/*
电脑组装
*/
//CPU抽象类
class CPU
{
public:
    // CPU()
    // {
    //     cout << "CPU构造函数" << endl;
    // }
    virtual void Calculate() = 0;
    ~CPU(){
        cout << "CPU停止工作" << endl;
    }
};
class GPU
{
public:
    // GPU()
    // {
    //     cout << "GPU构造函数" << endl;
    // }
    virtual void Display() = 0;
    ~GPU(){
        cout << "GPU停止工作" << endl;
    }
};
class RAM
{
public:
    // RAM()
    // {
    //     cout << "RAM构造函数" << endl;
    // }
    virtual void Memory() = 0;
    ~RAM(){
        cout << "RAM停止工作" << endl;
    }
};

//电脑类，让三个主要部件运行起来
class PC 
{
public: 
    //构造函数中传入三个零件
    PC(CPU * cpu, GPU * gpu, RAM * ram)
    {
        m_cpu = cpu;//m_cpu->new 
        m_gpu = gpu;
        m_ram = ram;        
    }
    void work()//提供工作的函数，调用每个零件工作的接口
    {
        m_cpu->Calculate();
        m_gpu->Display();
        m_ram->Memory();
    }
    ~PC()//这里m_cpu=cpu ,指向了堆区内存，
    {
        if(m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if(m_gpu != NULL)
        {
            delete m_gpu; 
            m_gpu = NULL;
        }
        if(m_ram != NULL)
        {
            delete m_ram;
            m_ram = NULL;
        }
    }
private:
    CPU * m_cpu;
    GPU * m_gpu;
    RAM * m_ram;
};
//具体零件厂商 
class  Intel : public CPU
{
    void Calculate()
    {
        cout << "Intel_CPU开始工作" << endl;
    }
    void Display()
    {
        cout << "Intel_GPU开始工作" << endl;
    }
    void Memory()
    {
        cout << "Intel_RAM开始工作" << endl;
    }
};

class  Nvida : public CPU, public GPU, public RAM
{
    void Calculate()
    {
        cout << "Nvida_CPU开始工作" << endl;
    }
    void Display()
    {
        cout << "Nvida_GPU开始工作" << endl;
    }
    void Memory()
    {
        cout << "Nvida_RAM开始工作" << endl;
    }
};
class  Lenovo : public CPU, public GPU, public RAM
{
    void Calculate()
    {
        cout << "Lenovo_CPU开始工作" << endl;
    }
    void Display()
    {
        cout << "Lenovo_GPU开始工作" << endl;
    }
    void Memory()
    {
        cout << "Lenovo_RAM开始工作" << endl;
    }
};

void test01()
{
    //第一台电脑的零件
    CPU * cpu = new Intel;//调用三个析构函数
    GPU * gpu = new Nvida;
    RAM * ram = new Lenovo;
    //创建第一台电脑
    PC * laptop1 = new PC(cpu,gpu,ram);//这里建立一个指针用来调用电脑工作
    cout << "第一台电脑工作" << endl;
    laptop1->work();
    delete laptop1;//laptop1~
    //delete cpu, gpu, ram; 
    return;
}
int main()
{
    test01();
    return 0;
}