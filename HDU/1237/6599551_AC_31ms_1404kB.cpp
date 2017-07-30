#include <stdio.h>  
#include <string.h>  
int main()  
{  
    char fuhao[100],str[205];  
    double num[100],sum;  
    while(gets(str)&&strcmp(str,"0")!=0)  
    {  
        int len=strlen(str);  
        int t=0,q=0;  
        memset(num,0,sizeof(num));  
        memset(fuhao,0,sizeof(fuhao));  
        for(int i=0;i<len;i++)  
        {  
            if(str[i]>='0'&&str[i]<='9')  
            {  
                double temp=0;  
                while(str[i]>='0'&&str[i]<='9')  
                temp=temp*10+str[i]-'0',i++;  
                num[q++]=temp;  
            }  
            if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')  
            fuhao[t++]=str[i];  
        }  
        memset(str,0,sizeof(str));  
        sum=num[0];  
        for(int i=1;i<q;i++)  
        num[i-1]=num[i];  
        for(int i=0;i<t;i++)  
        {  
            if(fuhao[i]=='*')  
            sum=sum*num[i];  
            else if(fuhao[i]=='/')  
            sum=sum/num[i];  
            else if(fuhao[i]=='+')  
            {  
                if(fuhao[i+1]=='*'||fuhao[i+1]=='/'&&i+1<t)  
                {  
                    double temp=num[i];  
                    while((fuhao[i+1]=='*'||fuhao[i+1]=='/')&&i+1<t)  
                    {  
                        if(fuhao[i+1]=='*')  
                        temp=temp*num[i+1];  
                        else  
                        temp=temp/num[i+1];  
                        i++;  
                    }  
                    sum=sum+temp;  
                }  
                else  
                sum=sum+num[i];  
            }  
            else if(fuhao[i]=='-')  
            {  
                if(fuhao[i+1]=='*'||fuhao[i+1]=='/'&&i+1<t)  
                {  
                    double temp=num[i];  
                    while((fuhao[i+1]=='*'||fuhao[i+1]=='/')&&i+1<t)  
                    {  
                        if(fuhao[i+1]=='*')  
                        temp=temp*num[i+1];  
                        else  
                        temp=temp/num[i+1];  
                        i++;  
                    }  
                    sum=sum-temp;  
                }  
                else  
                sum=sum-num[i];  
            }  
        }  
        printf("%.2lf\n",sum);  
    }  
    return 0;  
}  