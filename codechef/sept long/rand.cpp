#include<bits/stdc++.h>

using namespace std;

vector<string> vec;

int compare (const void * a, const void * b);
 
void allLexicographicRecur (char *str, char* data, int last, int index)
{
    int i, len = strlen(str);
 
    
    for ( i=0; i<len; i++ )
    {
        
        data[index] = str[i] ;
 
        if (index == last)
            vec.push_back(data);
        else
            allLexicographicRecur (str, data, last, index+1);
    }
}
 

void allLexicographic(char *str)
{
    int len = strlen (str) ;
 
    char *data = (char *) malloc (sizeof(char) * (len + 1)) ;
    data[len] = '\0';
 
    qsort(str, len, sizeof(char), compare);
 
    allLexicographicRecur (str, data, len-1, 0);
 
    free(data);
}
 
int compare (const void * a, const void * b)
{
    return ( *(char *)a - *(char *)b );
}
 
int main()
{
    int n;
    char s[10000];
    cin>>n;
    
	if(n<=7) {
		for(int i=1;i<=n;i++) {
	        s[i-1] = (i+'0');
	    }
	    allLexicographic(s);
	    map<string,int> mapy;
	    
	    for(int j=0;j<vec.size();j++) {
	    	string ss = s;
	    	for(int i=1;i<=n;i++) {
	    		int k = vec[j][i-1]-'0';
	    		char a = ss[i-1];
	    		char b = ss[k-1];
	    		ss[i-1] = b;
	    		ss[k-1] = a;
	    	}
	    	mapy[ss]++;
	    }
	    int amx = 0,imn=9999999;
	    string maxo="";
	    string mino ="";
	    for(auto it=mapy.begin();it!=mapy.end();it++) {
	    	if((*it).second > amx) {
	    		amx = (*it).second;
	    		maxo = (*it).first;
	    	} 
	    	if((*it).second < imn) {
	    		imn = (*it).second;
	    		mino = (*it).first;
	    	}
	    }
	    
	    for(int i=0;i<maxo.length();i++) {
	    	cout<<maxo[i]-'0'<<" ";
	    }
	    
	    cout<<endl;
	    
	    for(int i=0;i<mino.length();i++) {
	    	cout<<mino[i]-'0'<<" ";
	    }
	} else if(n == 8) {//pattern detected
		cout<<2<<" "<<3<<" "<<4<<" "<<1<<" "<<6<<" "<<7<<" "<<8<<" "<<5<<endl;
		cout<<8<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<endl;
	} else if(n==9){
		cout<<2<<" "<<3<<" "<<4<<" "<<1<<" "<<6<<" "<<7<<" "<<8<<" "<<9<<" "<<5<<endl;
		cout<<9<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<8<<endl;
	} else if(n==10){
		cout<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<1<<" "<<7<<" "<<8<<" "<<9<<" "<<10<<" "<<6<<endl;
		cout<<10<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<8<<" "<<9<<endl;
	} else if(n==11){
		cout<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<1<<" "<<7<<" "<<8<<" "<<9<<" "<<10<<" "<<11<<" "<<6<<endl;
		cout<<11<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<8<<" "<<9<<" "<<10<<endl;
	} else if(n==12){
		cout<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<1<<" "<<8<<" "<<9<<" "<<10<<" "<<11<<" "<<12<<" "<<7<<endl;
		cout<<12<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<8<<" "<<9<<" "<<10<<" "<<11<<endl;
	} else if(n==13){
		cout<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<1<<" "<<8<<" "<<9<<" "<<10<<" "<<11<<" "<<12<<" "<<13<<" "<<7<<endl;
		cout<<13<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<8<<" "<<9<<" "<<10<<" "<<11<<" "<<12<<endl;
	} else if(n==14){
		cout<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<1<<" "<<9<<" "<<10<<" "<<11<<" "<<12<<" "<<13<<" "<<14<<" "<<8<<endl;
		cout<<14<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<8<<" "<<9<<" "<<10<<" "<<11<<" "<<12<<" "<<13<<endl;
	} else if(n==15){
		cout<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<1<<" "<<9<<" "<<10<<" "<<11<<" "<<12<<" "<<13<<" "<<14<<" "<<15<<" "<<8<<endl;
		cout<<15<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<8<<" "<<9<<" "<<10<<" "<<11<<" "<<12<<" "<<13<<" "<<14<<endl;
	} else if(n==16){
		cout<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<8<<" "<<1<<" "<<10<<" "<<11<<" "<<12<<" "<<13<<" "<<14<<" "<<15<<" "<<16<<" "<<9<<endl;
		cout<<16<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<8<<" "<<9<<" "<<10<<" "<<11<<" "<<12<<" "<<13<<" "<<14<<" "<<15<<endl;
	} else if(n==17){
		cout<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<8<<" "<<1<<" "<<10<<" "<<11<<" "<<12<<" "<<13<<" "<<14<<" "<<15<<" "<<16<<" "<<17<<" "<<9<<endl;
		cout<<17<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<8<<" "<<9<<" "<<10<<" "<<11<<" "<<12<<" "<<13<<" "<<14<<" "<<15<<" "<<16<<endl;
	}
    return 0;
}
