#include <iostream>
using namespace std;

int main()
{
    int klimit, swine;               //���������ÿ�־�����klimit���Ƶ���������swine

    cin >> klimit >> swine;

    int v_wine1,v_wine2,v_wine3;    //�������־Ƶı�����ʼ����1,2,3
    
    int count = 0;                  //�ܵķ���count����

    for ( v_wine1 = 0; v_wine1 <= klimit ; v_wine1++)            //���ڵ�һ�־���˵����0��klimit���б���
    {
        if (v_wine1 > swine)                                    //��һ�־Ƴ������ޣ������˳�ѭ��
        {
            break;
        }
        for ( v_wine2 = 0; v_wine2 <= klimit; v_wine2++)        //�ڶ��־�Ҳ��0��klimit���б���
        {
            if(v_wine1+v_wine2 > swine)                         //����͵�һ�־Ƽ������Ѿ��������ޣ��˳�ѭ��
            {
                break;
            }
            if(swine - v_wine1 - v_wine2 <= klimit)             //�ж�ʣ�µĵ����־��Ƿ񳬹���������
            {
                count++;
                //cout << v_wine1 << ' ' << v_wine2 << ' ' << swine - v_wine1 - v_wine2 << '\n'; //������������Ľ�
            }
        }
        
    }
    cout << count;
    return 0;
}
