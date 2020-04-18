
#include <iostream>

struct StructClass{
	std::string localstr;
	StructClass(std::string str){
		localstr=str;
	}
	void print(){
		std::cout<<localstr;
	}
};

int main(int argc, char **argv){
	StructClass *sc = new StructClass(" Hello World ! ");
	sc->print();
	return 0;
}
