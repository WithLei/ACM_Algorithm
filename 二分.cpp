int Search(int num,int low,int high)  
{  
    int mid;  
    while(low <= high)  
    {  
        mid = (low+high)/2;  
        if(num >= b[mid])  
            low= mid+1;  
        else  
            high = mid-1;  
    }  
    return low;  
}  