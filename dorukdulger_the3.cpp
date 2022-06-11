/*
    Doruk Dulger 
	   THE3
*/
#include <iostream>
#include <string>

using namespace std;

bool sourcecheck(string word){
	unsigned int length = word.length();
	int cnt = 0;
	for (unsigned int i = 0; i < length;){
       if(('a' <= word.at(i)) && (word.at(i) <= 'z')){
		   i+=1;
		   cnt += 1;
	   }
	   else{
		   return false;
	   }
    }
	if(cnt == 0){
		  return false;
	   }
	return true;
}

bool searchcheck(string word, string sourceword){
	unsigned int length = word.length();
	int cnt = 0;
	for (unsigned int i = 0; i < length;){
       if(('a' <= word.at(i)) && (word.at(i) <= 'z')){
		   i+=1;
		   cnt+=1;
	   }
	   else if(word.at(i) == '?'){
		   i+=1;
	   }
	   else{
		   return false;
	   }
    }
	if(length > sourceword.length()){
		  return false;
	   }
	if(cnt == 0){
		  return false;
	   }
	return true;
}

void info(){
	cout << "This program searches a search string in a source string with the option of wildcards." << endl;
	cout << "" << endl;
	cout << "Example inputs with their meaning in parentheses:" << endl;
	cout << "1 thislectureisawesome (to enter a new source string)" << endl;
	cout << "2 lecture (to enter a new search string)" << endl;
	cout << "2 t?r? (to enter a search string with wildcards)  " << endl;
	cout << "3 (to exit the program)" << endl;
}

bool choicecheck(string choice){
	 string bos;
	 if(choice == "3"){
		 cout << "See you!" << endl;
		 return 0;
		  }
	 else if(choice == "1" || choice == "2"){
		 return 1;
	 }
	 else{	
		 cout << "Choice can be 1, 2 or 3! Try again." << endl;
		 return 0;
	 }
}

void search(string word, string sourceword){
	char x;
	int cnt = 0;
	x = '"';
	int Wlength = word.length();
	int Slength = sourceword.length();
    int f = word.find('?');
	int ilimiter = Slength - Wlength;
	if (f == string::npos){
	   for (int i = 0; i <= ilimiter ; i++){
        string founded = sourceword.substr(i,Wlength);
        if(word == founded){
            int index = i;
			cnt += 1;
            cout << endl << x << founded << x << " has been found at index " << index;
		}
	  }
	}
	
	else{
		string h, founded;
		int c;
		h = word;
		for (unsigned int i = 0; i < h.length();){
          if(h.at(i) == '?'){
		    h = h.replace(i,1,"");
	        }
		  else{
			  i++;
		  }  
		}
	    int hL = h.length();

		for (int i = 0; i <= ilimiter ; i++){
          founded = sourceword.substr(i,Wlength);
		   c = 0;
          for (int vx = 0; vx < Wlength; vx++){
             if(('a' <= word.at(vx)) && (word.at(vx) <= 'z')){
		          if(word.at(vx) == founded.at(vx)){
				     c += 1;
				     if(c == hL){
						int index = i;
					    cnt += 1;
					    cout << endl << x << founded << x << " has been found at index " << index;
						break;
				           }
			          }
			 }
	      }
	    }
	}
	
    if(cnt == 0){
		cout <<" no match has been found.";
	}
}


void inputcheck(string& choice, string& word, string& sourceword){
	char x;
	x = '"';	
	  if(choice == "1"){ 
		 if (sourcecheck(word)){
		    sourceword = word;
		    cout << "Source word has been changed to "<< x << sourceword <<  x  << endl;
		 }
		 else{
			 cout << "Wrong input format! Try again." << endl;
		 }
	 }
	   else if(choice == "2"){
		 if(sourceword == ""){
			 cout << "Wrong input format! Try again." << endl;
		  }
		 else if(searchcheck(word, sourceword)){
			 cout << "For the source word " << x << sourceword <<  x << " and search word " << x << word <<  x << ",";
			 search(word, sourceword);
			 cout << endl;
		  }
	     else{
		   cout << "Wrong input format! Try again." << endl;
	      }
	 }
}


int main()
{
	string sourceword = "", word = "", choice = "";
	info();
	while(choice != "3"){
		 cout << "" << endl;
	     cout << "Enter your choice and string: ";
	     cin >> choice;
		if (choicecheck(choice)){
		 cin >> word;
		 inputcheck(choice, word, sourceword);
		}
	}
	
	return 0;
}