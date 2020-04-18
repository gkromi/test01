
#include <iostream>

#define SET "setApp.conf"

using namespace std;

int checkConfigFile(){
	ifstream fileIn,fileInD;
	ofstream fileOut;
	int line_count=0;
	char ch;
	
	int checkBit[7];
	for(unsigned int x=0;x<sizeof(checkBit)/sizeof(int);x++){
		checkBit[x] = 0;
	}
	
	char t_key[64],t_value[64];
	char line_key[5][64];
	char line_value[5][64];
	
	short int t_value_size =  sizeof(t_value)/sizeof(char);
	short int t_key_size = sizeof(t_key)/sizeof(char);
	short int t_key_length = 0, t_value_length = 0;
	
	fileIn.open(SET);
	if(fileIn){
		checkBit[0]=1; //conf file available
		while(fileIn){
			fileIn.get(ch);
			if(ch=='<'){
				//file : <key>
				fileIn.get(ch); //skip '<'
				for(int i=0;ch!='>' && i < t_key_size;i++){
					t_key[i]=ch;
					t_key_length++;
					fileIn.get(ch);
				}
				t_key[t_key_length]='\0';
				if(t_key[0]=='\0'){
					cout<<" Error : "<<SET<<" Line : "<<line_count<<" 1 : Empty"<<endl;
				} else {
					checkBit[1]=1; //conf : first entity (key)
				}
				if(ch=='>'){
					fileIn.get(ch); //skip '>'
					//file :  >some text;
					for(int j=0;ch!=';' && j < t_value_size;j++){
						t_value[j]=ch;
						t_value_length++;
						fileIn.get(ch);
					}
					t_value[t_value_length]='\0';
					if(t_value[0]=='\0'){
						cout<<" Error : "<<SET<<" Line : "<<line_count<<" 2 : Empty"<<endl;
					} else {
						checkBit[2]=1; //conf : second entity (value)
					}
				}
				if(checkBit[1] && checkBit[2])
						checkBit[3]=1; //line - No error
				if(checkBit[1]){
					for(int col=0;col<t_key_length;col++)
						line_key[line_count][col]=t_key[col];
					if(checkBit[2]){
						for(int col=0;col<t_value_length;col++)
							line_value[line_count][col]=t_value[col];
					}else{
						checkBit[3]=0;
					}						
				}else{
					checkBit[3]=0;
				}
				line_count++;
				t_key_length=0;
				t_value_length=0;
			}
			if(checkBit[0]){
				if(!checkBit[3])
					cout<<" Error : While parsing "<<SET<<" \n";
			}
		}
		fileIn.close();
		for(int i=0;i<line_count;i++){
			cout<<i<<" ";
			for(int j=0;line_key[i][j]!='\0';j++){
				cout<<line_key[i][j];
			}
			cout<<" : ";
			for(int k=0;line_value[i][k]!='\0';k++){
				cout<<line_value[i][k];
			}
			cout<<endl;
		}
	}else{	/*File not found, Create a new config file, nothing assigned*/
		fileOut.open(SET);
		fileOut<<"<key>"<<"test_key;\n";
		fileOut<<"<set>off"<<";\n";
		fileOut.close();
		cout<<"\n Creating a new "<<SET<<" file \n";
	}
	return 0;
}

int main(int argc, char **argv){
	checkConfigFile();
	return 0;
}
