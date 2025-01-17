    #include<stdio.h>
    #define CAPACITY 5
    int top=-1,ele;
    int stack[CAPACITY];
    void push(int);
    int pop();
    int peek();
    void traverse();
    int isfull();
    int isempty();
    
    int main()
    {
    	int peekvalue,popvalue,c=1,data,ch;
    
    	while(1)
    	{
    		printf("1. Push\n");
    		printf("2. Pop\n");
    		printf("3. Peek\n");
    		printf("4. Traverse\n");
    		printf("5. Exit\n");
    		printf("Enter your choice ");
    		scanf("%d",&ch);
    
    		switch(ch)
    		{
    			case 1: printf("Enter %d th element: ",c);
    			        scanf("%d",&data);
    					push(data);
    					c++;
    					break;
    			
    			case 2: popvalue=pop();
    			        printf("Popped: %d\n",popvalue);
    					break;
    
    			case 3: peekvalue=peek();
    			        printf("The Peekvalue : %d \n",peekvalue);
    					break;
    
    			case 4: traverse();
    			         break;
    
    			case 5: printf("Thanku you User");
    			        return 0;
    					break;
    
    			default : printf("Invalid input");
    			          break; 
    		}
    
    	}
    	return 0;
    }
    
     void push(int data)
     {
    	if(!isfull())
    	{
    		top++;
    		stack[top]=data;
            printf("Inserted Successfully \n");
    	}else
    	printf("Stack Full \n");
     }
    
     int pop()
     {
    	if(!isempty())
    	{
    		return stack[top--];
    	}else
    	printf("Stack empty\n");
     }
    
     int peek()
     {
    	if(!isempty())
    	{
    		return stack[top];
    	}else
    	printf("Stack Empty \n");
     }
    
     void traverse()
    { 
    	 if(!isempty()){
    	for(int i=0;i<=top;i++)
    	{
    		printf("%d\n",stack[i]);
    	}
    	 }
    	else
    	printf("Stack empty");
    }
    
    
    int isfull()
    {
    	if(top==CAPACITY-1)
    	return 1;
    	else
    	return 0;
    }
    
    int isempty()
    {
    	if(top==-1)
    	return 1;
    	else
    	return 0;
    }
