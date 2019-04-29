#include <stdio.h>
#include <string.h>
#include <conio.h> //this library allows to use clrscr().


//function prototypes
char encrypt_ltr(char alpha, int key);
void encrypt_text(char text[], int key);
char decrypt_ltr(char alpha, int key);
void decrypt_text(char text[], int key);
int locate_index(char cipher_alpha[], char alpha_locate);
char* encrypt_sub(char *text, char cipher_alpha[]);
char* decrypt_sub(char *text, char cipher_alpha[]);


int main()
{
    
    int option, key;
    char text[100];
    char cipher_alpha[26] = {'h','g','q','t','y','p','l','j','m','d','w','i','z','x','c','f','s','o','r','b','n','u','a','k','v','e'}; //substitution alphabet.
    
    printf("****Welcome to the encryption and decryption program****");
    printf("\nPlease choose the following options: \n");
    printf("To encrypt a message using a rotation cipher with a key, enter 1\n");
    printf("To decrypt a message using a rotation cipher with a key, enter 2\n");
    printf("To encrypt a message using a substitution cipher, enter 3\n");
    printf("To decrypt a message using a substitution cipher, enter 4\n");
    printf("To exit the program, enter 5\n");
    scanf("%d", &option);
    
    clrscr(); //clears the screen once an appropriate choice from the menu has been made.
    
    switch(option)
    {
      
      //executes if users enters 1  
    case 1:  
        
    {
       
        printf("Please enter message to be encrypted:\n"); //prompts user to type the message to be encrypted.
        while(getchar()!='\n');//stores input into the variable text, which is a string.
        scanf("%99[^\n]s", text);
        
        printf("Please enter the key:\n"); //prompts user to the enter the value by which the alphabet is rotated.
        scanf("%d", &key);
  
        //loop to check if the key that is entered is between 0 and 26.
        if (key <= 0 || key >= 27) 
        {
		printf("Error, please make sure the key is between 0 and 26"); //displays an error message if the key is out of the range (0 - 26).
		return 0; //exits the program due to error.
        }
        
        encrypt_text(text, key); //call the function to encrypt the message.
        printf("The encrypted message is: %s\n", text); //display the encrypted message.
        
        break;
    }
    
    
    case 2:
    {
        
        printf("Please enter message to be decrypted:\n"); //prompts user to type the message to be decrypted.
        while(getchar()!='\n');
        scanf("%99[^\n]", text); //stores input into the variable text, which is a string.
  
        printf("Please enter the key:\n"); //prompts user to the enter the value by which the alphabet is rotated.
        scanf("%d", &key);
  
        //loop to check if the key that is entered is between 0 and 26.
        if (key <= 0 || key >= 27) 
        {
		printf("Error, please make sure the key is between 0 and 26"); //displays an error message if the key is out of the range (0 - 26).
		return 0; //exits the program due to error.
        }
        
        decrypt_text(text, key); //call the function to decrypt the message.
        printf("The decrypted message is: %s\n", text); //display the decrypted message.  
        
        break;
    }
     
     
    case 3:
    {
           
        printf("Please enter the message to be encrypted\n"); //prompts user to type text to encrypt.
        while(getchar()!='\n');
        scanf("%99[^\n]", text); //stores input in the variable text, which is a string.   
        
        char *encrypted_text = encrypt_sub(text, cipher_alpha); //calls the function to decrypt the text.
        printf("The encrypted message is: %s\n", encrypted_text); //displays the decrypted text.    
        
        break;    
    }
     
     
    case 4:
    {
        
        printf("Please enter the message to be decrypted\n"); //prompts user to enter a text to decrypt.
        while(getchar()!='\n');
        scanf("%99[^\n]", text); //stores input in the variable text, which is a string.
        
        char *decrypted_text = decrypt_sub(text, cipher_alpha); //calls the function to decrypt the text.
        printf("The decrypted message is: %s\n", decrypted_text); //displays the decrypted text.
      
        break;
    }
        
        
    case 5:
    {
        return(0);
        break;
    }
    
    
    default:    
    {
        printf("Please choose a valid option\n");   
    }
        
    }    
 return 0;
}
    
    
    
    //this function encrypts one single letter at a time, considering both lower case and upper case.
    char encrypt_ltr(char alpha, int key) 
    {
    if (alpha >= 'A' && alpha <= 'Z') //considers upper case letters.
    {
      alpha = ((alpha-'A') + key) % 26 + 'A'; //encrypts a letter by adding the particular key to the ASCII value.
    }
    else if(alpha >= 'a' && alpha <= 'z') //considers lower case letters.
    {
      alpha = ((alpha-'a') + key) % 26 + 'a'; //encrypts a letter by adding the particular key to the ASCII value.
    }

    return alpha; //returns the encrypted letters.
    }


    //this function encrypts a message, which consists of encrypting every letter of that message.
    void encrypt_text(char text[], int key)
    {
    // declare and or initialise variables.
    int i = 0;
    char result;
  
    while (result = text[i]) //entered message is encrypted using this loop.
    {
    result = encrypt_ltr(result, key); 
    text[i] = result; //the result of above calculation is now stored in the string text, which now contains the encrypted message.
    i++;
  }
}
    
    
    
    //this function decrypts one single letter at a time, considering both lower case and upper case.
    char decrypt_ltr(char alpha, int key) 
    {
    if (alpha >= 'A' && alpha <= 'Z') //considers upper case letters.
    {
      alpha = ((alpha-'A') - key + 26) % 26 + 'A'; //decrypts a letter by subtracting the particular key to the ASCII value.
    }
    else if(alpha >= 'a' && alpha <= 'z') //considers lower case letters.
    {
      alpha = ((alpha-'a') - key + 26) % 26 + 'a'; //decrypts a letter by subtracting the particular key to the ASCII value.
    }

    return alpha; //returns the decrypted letters.
    }


    //this function decrypts a message, which consists of decrypting every letter of that message.
    void decrypt_text(char text[], int key)
    {
    // declare and or initialise variables.
    int i = 0;
    char result;
  
    while (result = text[i]) //entered message is encrypted using this loop.
    {
    result = decrypt_ltr(result, key); 
    text[i] = result; //the result of above calculation is now stored in the string text, which now contains the encrypted message.
    i++;
  }
}
    
    
    
    //this function acquires the cipher index of each letter in the text.
    int locate_index(char cipher_alpha[], char alpha_locate)
    {
    for(int k = 0 ; k < 26; k ++){
    if(cipher_alpha[k] == alpha_locate) //compares between the letters in the text and the substitution alphabet.
    {
      return k;
    }
  }
  return -1;
} 
 
  
    char* encrypt_sub(char *text,char cipher_alpha[]) //Function prototype.
    {
    int txtlength = strlen(text); //Acquire length of the text using the strlen function to know how many iterations is required.
    char *encrypted_text = (char *) malloc(sizeof(char)*txtlength);

    //convert to lower case as it is easier to work with only 26 letters, as opposed to a larger value.
    // 'a' is subtracted from the text to acquire the encryption index and determine if character is between 0 to 26.
    for(int k = 0; k < txtlength; k++){
    int encryption_index = tolower(text[k]) - 'a'; 
    if(encryption_index >= 0 && encryption_index < 26){
      encrypted_text[k] = cipher_alpha[encryption_index];
    }else{
      encrypted_text[k] = text[k]; 
    }
  }
  return encrypted_text; //Return the encrypted text to the function.
}    
    
    
    
    //this function decrypts the entered text.
    char *decrypt_sub(char *text,char cipher_alpha[]) 
    { 
    int txtlength = strlen(text); // Acquire length of the text using the strlen function.
    char *decrypted_text = (char *) malloc(sizeof(char)*txtlength);
  
  
    //convert to lower case as it is easier to work with only 26 letters, as opposed to a larger value.
    //'a' is subtracted from the text to acquire the encryption index and determine if character is between 0 to 26.
    for(int k = 0; k < txtlength; k++)
    {
    int decryption_index = tolower(text[k]) - 'a';
    if(decryption_index >= 0 && decryption_index < 26){
      int cipher_alpha_index = locate_index(cipher_alpha, tolower(text[k])); 
      decrypted_text[k] = 'a' + cipher_alpha_index;
    }else{
      decrypted_text[k] = text[k];
    }
  }
  return decrypted_text; //Return the decrypted text to the function.
}    
        
        


