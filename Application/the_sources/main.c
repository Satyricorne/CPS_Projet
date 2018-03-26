#include <stdio.h>


int int main(int argc, char const *argv[]) {
  if(argc != 3){
    printf("Problème d'argument vous devait saisir l'executable, l'option et le fichier à modifier")
  }else{
    if(argv[1] == "-b" || argv[2] == "-b"){
      binariser(argv[2]);
    }if(argv[1] == "-g" || argv[2] == "-g"){
      
    }
  }
}
