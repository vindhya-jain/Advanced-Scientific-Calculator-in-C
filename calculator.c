#include<stdio.h>
#include<math.h>
#include<string.h>

void decToBinary(int n);
void decToOctal(int n);
void decToHex(int n);

int main()
{
    char exp[100];
    printf("Enter the expression\n");
    scanf("%s",exp); //scanning entered expression as a string

    //checking syntax of entered expression
    for(int i=0;i<strlen(exp);i++){
        if((exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^') && 
        (exp [i+1]=='+' || exp[i+1]=='-' || exp[i+1]=='*' || exp[i+1]=='/' || exp[i+1]=='^'))
        {
            printf("SYNTAX ERROR");
            return 0;
        }
    }

    //for number system conversions
    int test=0;
    for(int i=0;i<strlen(exp);i++)
    {
        //checking if input expression has any operator in it
        if(exp[i]<48 || exp[i]>57){
            test++;
        }

        else if(i==(strlen(exp)-1) && test==0)
        {
            //following options provided to the user if no operator is found
            printf("convert number to:\n");
            printf("1. binary\n");
            printf("2. octal\n");
            printf("3. hexadecimal\n");
            int convert;
            scanf("%d",&convert);

            int decimal=0;

            for(int j=0;j<strlen(exp);j++)
            {
                decimal = decimal*10 + (int)(exp[j]-'0');
            }

            switch(convert)
            {
                case 1: 
                decToBinary(decimal);
                return 0;

                case 2:
                decToOctal(decimal);
                return 0;

                case 3:
                decToHex(decimal);
                return 0;
            }
        }
    }

    {   //solving and condensing the sin function
        float degree=0,radian,sinvalue;
        char value[20];
        for(int i=0;i<strlen(exp);i++)
        {
            //checking the occurance of 'sin' in exp
            if(exp[i]=='s' && exp[i+1]=='i' && exp[i+2]=='n')
            {
                int index;
                for(int j=i+3;j<strlen(exp);j++)
                {
                    //copying the angle into a float varible 'degree'
                    if(exp[j]!='+' && exp[j]!='-' && exp[j]!='*' && exp[j]!='/' && exp[j]!='^'){
                        degree = degree*10 + (float)(exp[j]-'0');
                        index=j;
                    }
                    else
                    break;
                }
                radian=0.0174533*degree; //converting degree to radians
                sinvalue=sin(radian); 
                sprintf(value,"%f",sinvalue); //function sprintf() converts float value into string

                for(int j=i;j<=index;j++)
                {
                    exp[j]='0'; //setting the 'sin[num]' elements of string as 0
                }
                
                int valueindex=0;
                for(int j=i;j<=index;j++)
                {
                    exp[j]=value[valueindex]; //copying value into original string
                    valueindex++;
                }

            }
        }
    }

    {   //similarly solving and condensing cos function
        float degree=0,radian,cosvalue;
        char value[20];
        for(int i=0;i<strlen(exp);i++)
        {
            if(exp[i]=='c' && exp[i+1]=='o' && exp[i+2]=='s')
            {
                int index;
                for(int j=i+3;j<strlen(exp);j++)
                {
                    if(exp[j]!='+' && exp[j]!='-' && exp[j]!='*' && exp[j]!='/' && exp[j]!='^'){
                        degree = degree*10 + (float)(exp[j]-'0');
                        index=j;
                    }
                    else
                    break;
                }
                radian=0.0174533*degree;
                cosvalue=cos(radian);
                sprintf(value,"%f",cosvalue);

                for(int j=i;j<=index;j++)
                {
                    exp[j]='0';
                }
                
                int valueindex=0;
                for(int j=i;j<=index;j++)
                {
                    exp[j]=value[valueindex];
                    valueindex++;
                }

            }
        }
    }

    {   //solving and condensing tan function
        float degree=0,radian,tanvalue;
        char value[20];
        for(int i=0;i<strlen(exp);i++)
        {
            if(exp[i]=='t' && exp[i+1]=='a' && exp[i+2]=='n')
            {
                int index;
                for(int j=i+3;j<strlen(exp);j++)
                {
                    if(exp[j]!='+' && exp[j]!='-' && exp[j]!='*' && exp[j]!='/' && exp[j]!='^'){
                        degree = degree*10 + (float)(exp[j]-'0');
                        index=j;
                    }
                    else
                    break;
                }
                radian=0.0174533*degree;
                tanvalue=tan(radian);
                sprintf(value,"%f",tanvalue);

                for(int j=i;j<=index;j++)
                {
                    exp[j]='0';
                }
                
                int valueindex=0;
                for(int j=i;j<=index;j++)
                {
                    exp[j]=value[valueindex];
                    valueindex++;
                }

            }
        }
    }

    {   //solving and condensing log function 
        float number=0,logvalue;
        char value[20];
        for(int i=0;i<strlen(exp);i++)
        {
        if(exp[i]=='l' && exp[i+1]=='o' && exp[i+2]=='g')
            {
                int index;
                for(int j=i+3;j<strlen(exp);j++)
                {
                    if(exp[j]!='+' && exp[j]!='-' && exp[j]!='*' && exp[j]!='/' && exp[j]!='^'){
                        number = number*10 + (float)(exp[j]-'0');
                        index=j;
                        }
                    else
                    break;
                }
                logvalue=log(number);
                sprintf(value,"%f",logvalue);
                for(int j=i;j<=index;j++)
                {
                    exp[j]='0';
                }                
                int valueindex=0;
                for(int j=i;j<=index;j++)
                {
                    exp[j]=value[valueindex];
                    valueindex++;
                }
            }
        }
    }

    float numbers[100]={0};
    char operators[100];
    int dec=1,o=0, flag=0, num=0;

    //separting the expression into separate 'numbers' and 'operators' arrays
    for(int i=0;i<strlen(exp);i++)
    {
        // condition for separating five (+,-,*,/,^) operators into an array.
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^'){
            operators[o]=exp[i];
            o++; //incrementing index in operators array
            flag=0; //resetting flag
            num++; //incrementing index in numbers array
            dec=1; //resetting decimal iterator
        }

        // checking for decimal
        else if(exp[i]=='.'){
            flag=1; 
        }
        
        else
        {
            // when flag is 0, implies the number is not coming after a decimal. following commands to be executed
            if(flag==0){
                numbers[num] = numbers[num]*10 + (float)(exp[i]-'0');
            }

            // when flag is 1, it implies the number is coming after decimal. following commands to be executed to correctly copy the number
            else if(flag==1){
                float temp=(float)(exp[i]-'0');
                numbers[num] = numbers[num] + temp/(float)(pow(10,dec));
                dec++;
            }
        }
    }

    //solving exponents first according to BIDMAS
    for(int i=0;i<=o;i++)
    {
        if(operators[i]=='^')
        {
            numbers[i]=pow(numbers[i],numbers[i+1]);
            for(int j=i+1;j<num;j++)
            {
                numbers[j]=numbers[j+1];
            }
            num--;
            for(int j=i;j<o;j++)
            {
                operators[j]=operators[j+1];
            }
            o--;
            i--;
        }
    }

    //performing division according to BIDMAS
    for(int i=0;i<=o;i++)
    {
        // checking operators array to see if the expression requires division
        if(operators[i]=='/')
        {
            // if '/' is there at i th position, we divide the i and i+1 index elements in numbers array
            numbers[i]=numbers[i]/numbers[i+1];

            //rearranging numbers array so that performed division is stored in i th index and following elements are shifted one index back
            for(int j=i+1;j<num;j++) 
            {
                numbers[j]=numbers[j+1];
            }
            num--;//because we have condensed two numbers and stored the value in one position after division, array size decreases by 1

            //similarly rearranging operators array.
            for(int j=i;j<o;j++)
            {
                operators[j]=operators[j+1];
            }
            o--;
            i--;// due to rearrangment of operators array, the i th index holds a different operator, and hence must be rechecked
        }
    }

    //similarly performing multiplication
    for(int i=0;i<=o;i++)
    {
        if(operators[i]=='*')
        {
            numbers[i]=numbers[i]*numbers[i+1];
            for(int j=i+1;j<num;j++)
            {
                numbers[j]=numbers[j+1];
            }
            num--;
            for(int j=i;j<o;j++)
            {
                operators[j]=operators[j+1];
            }
            o--;
            i--;
        }
    }

    //performing addition
    for(int i=0;i<=o;i++)
    {
        if(operators[i]=='+')
        {
            numbers[i]=numbers[i]+numbers[i+1];
            for(int j=i+1;j<num;j++)
            {
                numbers[j]=numbers[j+1];
            }
            num--;
            for(int j=i;j<o;j++)
            {
                operators[j]=operators[j+1];
            }
            o--;
            i--;
        }
    }

    // performing subtraction
    for(int i=0;i<=o;i++)
    {
        if(operators[i]=='-')
        {
            numbers[i]=numbers[i]-numbers[i+1];
            for(int j=i+1;j<num;j++)
            {
                numbers[j]=numbers[j+1];
            }
            num--;
            for(int j=i;j<o;j++)
            {
                operators[j]=operators[j+1];
            }
            o--;
            i--;
        }
    }
    // final answer resides in first index of number array.
    printf("=%f",*numbers);
}

void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];
  
    // counter for binary array
    int i = 0;
    while (n > 0) {
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
  
    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

void decToOctal(int n)
{
 
    // array to store octal number
    int octalNum[100];
 
    // counter for octal number array
    int i = 0;
    while (n != 0) {
 
        // storing remainder in octal array
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }
 
    // printing octal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", octalNum[j]);
}

void decToHex(int n)
{
    int remainder,quotient;
	int i=1,j,temp;
	char hexadecimalNumber[100];

	quotient = n;
	while(quotient!=0) {
		temp = quotient % 16;
		//To convert integer into character
		if( temp < 10)
		temp =temp + 48;
        else
		temp = temp + 55;
		hexadecimalNumber[i++]= temp;
		quotient = quotient / 16;
	}
	for (j = i -1 ;j> 0;j--)
	      printf("%c",hexadecimalNumber[j]);
}