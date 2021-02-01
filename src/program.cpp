
#include <ExtAVLTree.hpp>
#include <fstream>


int main() {

	ExtAVLTree *tree = new ExtAVLTree();
	#pragma region Read
	ifstream DocRead("doc/Veri.txt");
  	string row = "";
  	if ( DocRead.is_open() ){
    	while ( getline(DocRead, row) ){
			//Satirin bosluk ile bitmediği durumda okuma hatalarının önüne gecer.
			if(row.back()!='#'){
				row+='#';
			}
			string data = "";
			string corp;
			string name;
			int date;
			int i = 0;
    		for (auto x : row) {
        		if (x == '#'){
					if(i==0){
						corp=data;
					}else if(i==1){
						name=data;
					}else if(i==2){
						date=stoi(data);
					}
        	    	data = "";
					i++;
        		}
        		else {
        		    data = data + x;
        		}

    		}
			tree->Insert(corp,name,date);
    	}
    	DocRead.close();
	}
	#pragma endregion

	tree->postOrder();
	/*	//Gorsellestirilmis inOrder cocuklarla birlikte yazma fonksiyonu.Daha fazla ayrıntı icin fonksiyonun icine girip
		//ic agacın yazma fonksiyonunu da parentOrder yapın.
		tree->parentOrder();
	*/



/*	//Programı sınamak için çok buyuk dosyalar olusturup kontrol edemedim. Onun yerine programı kırmak icin yakın sayılar kullandım.

	IntAVLTree *introot = new IntAVLTree();

	
	introot->Insert("Mert",10);
	introot->Insert("Ayşe",20);
	introot->Insert("Robo",10);
	introot->Insert("Reis",20);
	introot->Insert("Helios",11);
	introot->Insert("Katos",9);
	introot->Insert("Interior",10);
	introot->Insert("Racer",12);
	introot->Insert("Momentum",11);
	introot->parentOrder();
*/
/*
	ExtAVLTree *root = new ExtAVLTree();

	root->Insert("A","Mert",10);
	root->Insert("A","Ayse",20); 

	root->Insert("B","Rakun",77);
	root->Insert("B","Jasmin",33);

	root->Insert("D","RiotVarior",35);
	root->Insert("D","Klantru",47); 
	root->Insert("D","RiotVarior",35);
	root->Insert("D","Klantru",47);


	root->Insert("B","Border",19);  
	root->Insert("B","Border",19);  

	root->Insert("C","Ksandra",13);
	root->Insert("C","Helixir",57); 
	root->Insert("C","Ksandra",13);
	root->Insert("C","Helixir",57); 
	 

	root->Insert("D","RiotVarior",35);
	root->Insert("D","Klantru",47); 
	root->Insert("D","RiotVarior",35);
	root->Insert("D","Klantru",47);

	root->Insert("C","Ksandra",13);
	root->Insert("C","Helixir",57);

	root->Insert("E","RiotVarior",35);
	root->Insert("E","Klantru",47); 
	root->Insert("E","RiotVarior",35);
	root->Insert("E","Klantru",47);
	root->Insert("E","RiotVarior",35);
	root->Insert("E","Klantru",47); 


	root->Insert("J","RiotVarior",35);
	root->Insert("J","Klantru",47);
	root->Insert("J","RiotVarior",35);

	root->Insert("F","Klantru",47); 
	root->Insert("F","RiotVarior",35);
	root->Insert("F","Klantru",47);
	root->Insert("F","RiotVarior",35);
	root->Insert("F","Klantru",47);

	root->Insert("G","Klantru",47); 
	root->Insert("G","RiotVarior",35);
	root->Insert("G","Klantru",47);
	root->Insert("G","RiotVarior",35);

	root->Insert("E","RiotVarior",35);
	root->Insert("E","Klantru",47);
	root->Insert("E","RiotVarior",35);
	root->Insert("E","Klantru",47);

	root->Insert("G","Klantru",47);
	root->Insert("G","Klantru",47);
	root->Insert("G","Klantru",47); 


	root->Insert("J","Klantru",47);
	root->Insert("J","Klantru",47);
	root->Insert("J","RiotVarior",35);

    root->postOrder();
	cout<<endl<<endl;
	root->parentOrder();
*/
	cin.ignore();

	return 0;
}