/*
Write a C program to implement a simple database system for a library. The database should store information about books and members. Each book record should contain the following details: book ID, title, author, and status (available or borrowed). Each member record should contain the following details: member ID, name, and borrowed book ID.
The program should provide the following functionalities:
Add a book/member record: The user should be able to add a new book/member record to a file. The details should be input by the user.
Display all book/member records: The user should be able to view all book/member records stored in the file.
Search a book/member record: The user should be able to search for a book/member record using the book/member ID.
Modify a book/member record: The user should be able to modify an existing book/member record. The user can input the book/member ID of the record that needs to be modified.
Delete a book/member record: The user should be able to delete a book/member record from the file. The user can input the book/member ID of the record that needs to be deleted.
Borrow a book: A member should be able to borrow a book. The system should update the bookâ€™s status and the memberâ€™s borrowed book ID.
Return a book: A member should be able to return a book. The system should update the bookâ€™s status and the memberâ€™s borrowed book ID.
The program should make use of pointers for file handling and data manipulation. The book/member record can be a structure. The file handling should be done using fread and fwrite functions, and the file should be opened in binary mode.
Remember to handle all edge cases and provide a user-friendly interface for the user to interact with the program.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxChar 50
#define MaxBorrow 10

char booksFile[]   = "Books.dat";
char membersFile[] = "Members.dat";


struct Book {
    int bookId;
    char title[MaxChar];
    char author[MaxChar];
    int status;
};


struct Member {
    int memberId;
    char name[MaxChar];
    int borrowed[MaxBorrow];
};


int isFileEmpty(char file[]){
    FILE* fp = fopen(file, "rb");
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    return size == 0 ? 1 : 0;
}

int isBookExists(int bId){
    FILE* fp = fopen(booksFile, "rb");
    if(fp == NULL){
        printf("Error! to open %s\n\n", booksFile);
        exit(-1);
    }

    struct Book bk;
    while(fread(&bk, sizeof(bk), 1, fp)){
        if(bk.bookId == bId){
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0; 
}

int isBookAvailable(int bId){
    FILE* fp = fopen(booksFile, "rb");
    if(fp == NULL){
        printf("Error! to open %s\n\n", booksFile);
        exit(-1);
    }

    struct Book bk;
    while(fread(&bk, sizeof(bk), 1, fp)){
        if(bk.bookId == bId && bk.status == 1){
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0; 
}

int isMemeberExists(int mId){
    FILE* fp = fopen(membersFile, "rb");
    if(fp == NULL){
        printf("Error! to open %s\n\n", booksFile);
        exit(-1);
    }

    struct Member mb;
    while(fread(&mb, sizeof(mb), 1, fp)){
        if(mb.memberId == mId){
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int isMemeberBorrowedBook(int mId, int bId){
    FILE* fp = fopen(membersFile, "rb");
    if(fp == NULL){
        printf("Error! to open %s\n\n", booksFile);
        exit(-1);
    }

    struct Member mb;
    while(fread(&mb, sizeof(mb), 1, fp)){
        if(mb.memberId == mId){
            for(int i = 0; i < MaxBorrow; i++){
                if(mb.borrowed[i] == bId){
                    fclose(fp);
                    return 1;
                }
            }
            break;
        }
    }

    fclose(fp);
    return 0;
}

void addMember() {
    FILE* fp = fopen(membersFile, "ab");
    if(fp == NULL){
        printf("Error! to open %s\n\n", membersFile);
        return;
    }

    struct Member mb;
    printf("Enter member Id: ");
    scanf("%d", &mb.memberId);
    getchar();

    if(isMemeberExists(mb.memberId)){
        printf("Member is alreday exists\n\n");
        fclose(fp);
        return;
    }

    printf("Enter member name: ");
    scanf("%[^\n]s", mb.name);
    getchar();

    for(int i = 0; i < MaxBorrow; i++){
        mb.borrowed[i] = -1;
    }

    fwrite(&mb, sizeof(mb), 1, fp);
    fclose(fp);
    printf("Member added successfully\n\n");
}

void displayMembers(){
    FILE* fp = fopen(membersFile, "rb");
    if(fp == NULL){
        printf("Error! to open %s\n", membersFile);
        return;
    }

    if(isFileEmpty(booksFile)){
        printf("%s is empty\n\n", membersFile);
        return;
    }

    struct Member mb;
    printf("Display all Members\n");
    printf("Member Id \t Name \t Borrowed Books \n");
    while(fread(&mb, sizeof(mb), 1, fp)) {
        printf("%d\t", mb.memberId);
        printf("%s\t", mb.name);
        for(int i = 0; i < MaxBorrow; i++){
            if(mb.borrowed[i] != -1){
                printf("%d, ", mb.borrowed[i]);
            }
        }
        printf("\n");
    }
    printf("File ended\n\n");
    fclose(fp);
}

void searchMember(){
    FILE* fp = fopen(membersFile, "rb");
    if(fp == NULL){
        printf("Error! to open %s\n", membersFile);
        return;
    }

    int mId;
    printf("Enter Member Id: ");
    scanf("%d", &mId);
    getchar();

    struct Member mb;
    while(fread(&mb, sizeof(mb), 1, fp)) {
        if(mId == mb.memberId){
            printf("Member founded\n");
            printf("Member Id \t Name \t Borrowed Books \n");
            printf("%d\t", mb.memberId);
            printf("%s\t", mb.name);
            for(int i = 0; i < MaxBorrow; i++){
                if(mb.borrowed[i] != -1){
                    printf("%d, ", mb.borrowed[i]);
                }
            }
            printf("\n\n");
            fclose(fp);
            return;
        }
    }

    printf("Member does not exists\n\n");
    fclose(fp);
}

int updateMemberFile(int modifiying, int deleteing, int borrwingBook, int returning, int mId, int bId){

    FILE* fpR = fopen(membersFile, "rb");
    if(fpR == NULL){
        printf("Error! to open %s\n", membersFile);
        exit(1);
    }

    FILE* fpW = fopen("temp.dat", "wb");
    if(fpW == NULL){
        printf("Error! to open temp.dat\n");
        exit(1);
    }

    struct Member mb;
    int flag = 0;

    // member borrowing a book
    if(borrwingBook){
        printf("Member Borrowing the Book\n");
        while(fread(&mb, sizeof(mb), 1, fpR)){
            if(mb.memberId == mId){
                int i = 0;
                for(; i < MaxBorrow; i++){
                    if(mb.borrowed[i] == -1){
                        mb.borrowed[i] = bId;
                        flag = 1; // successfully borrorwed book
                        break;
                    }
                }
                if(i >= MaxBorrow){
                    printf("Can't borrowed. Member excede borrowed limit\n\n");
                }
            }
            fwrite(&mb, sizeof(mb), 1, fpW);
        }
    }

    if(returning){
        printf("Member returning the Book\n");
        while(fread(&mb, sizeof(mb), 1, fpR)){
            if(mb.memberId == mId){
                int i = 0;
                for(; i < MaxBorrow; i++){
                    if(mb.borrowed[i] == bId){
                        mb.borrowed[i] = -1;
                        flag = 2; // successfully borrorwed book
                    }
                }
            }
            fwrite(&mb, sizeof(mb), 1, fpW);
        }
    }

    // modify the existing member
    if(modifiying){
        printf("Modifying Member\n");
        while(fread(&mb, sizeof(mb), 1, fpR)){
            if(mb.memberId == mId){
                char ch;
                printf("Do u want to Update Memeber's Id\n");
                printf("Enter 'y' for Yes or 'n' for No: ");
                scanf("%c", &ch);
                getchar();
                if(ch == 'y'){
                    printf("Enter Memeber's new Id: ");
                    scanf("%d", &mb.memberId);
                    getchar();
                }
                
                printf("Do u want to Update Memeber's Name\n");
                printf("Enter 'y' for Yes or 'n' for No: ");
                scanf("%c", &ch);
                getchar();
                if(ch == 'y'){
                    printf("Enter Memeber's new Name: ");
                    scanf("%[^\n]s", mb.name);
                    getchar();
                }

                printf("Do u want to Update Memeber's borrowed book\n");
                printf("Enter 'y' for Yes or 'n' for No: ");
                scanf("%c", &ch);
                getchar();
                if(ch == 'y'){
                    mb.borrowed[0] = 1;
                    for(int i = 0; i < MaxBorrow; i++){
                        if(mb.borrowed[i] != -1){
                            printf("Old borrowed Book Id is: %d\n", mb.borrowed[i]);
                            printf("Update borrowed Book Id to: ");
                            scanf("%d", &mb.borrowed[i]);
                        }
                    }
                }
            }

            fwrite(&mb, sizeof(mb), 1, fpW);
        }
        flag = 3; // Member is successfully modified
    }

    // delete the existing member
    if(deleteing){
        printf("Deleting Member\n");
        while(fread(&mb, sizeof(mb), 1, fpR)){
            if(mb.memberId == mId){
                continue;
            }

            fwrite(&mb, sizeof(mb), 1, fpW);
        }
        flag = 4; // member is deleted
    }

    fclose(fpR);
    fclose(fpW);
    remove(membersFile);
    rename("temp.dat", membersFile);
    remove("temp.dat");

    // flag = 1 => successfully borrorwed book
    // flag = 2 => successfully returned book
    // flag = 3 => successfully modified member
    // flag = 4 => successfully deleted member
    // flag = 0 => no chnages or some error
    return flag;
}

int updateBooksFile(int modifying, int deleting, int borrowing, int returning, int bId){
    FILE* fpR = fopen(booksFile, "rb");
    if(fpR == NULL){
        printf("Error! to open %s\n", booksFile);
        exit(1);
    }

    FILE* fpW = fopen("temp.dat", "wb");
    if(fpW == NULL){
        printf("Error! to open temp.dat\n");
        exit(1);
    }

    struct Book bk;
    int flag = 0;
    if(borrowing){
        printf("Book is borrowing\n");
        while(fread(&bk, sizeof(bk), 1, fpR)){
            if(bk.bookId == bId){
                bk.status = 0;
            }
            fwrite(&bk, sizeof(bk), 1, fpW);
        }
        flag = 1;
    }

    if(returning){
        printf("Book is returning\n");
        while(fread(&bk, sizeof(bk), 1, fpR)){
            if(bk.bookId == bId){
                bk.status = 1;
            }
            fwrite(&bk, sizeof(bk), 1, fpW);
        }
        flag = 2;
    }

    if(modifying){
        while(fread(&bk, sizeof(bk), 1, fpR)){
            if(bk.bookId == bId){
                char ch;
                printf("Do u want to Update Book's Id\n");
                printf("Enter 'y' for Yes or 'n' for No: ");
                scanf("%c", &ch);
                getchar();
                if(ch == 'y'){
                    printf("Enter Book's new Id: ");
                    scanf("%d", &bk.bookId);
                    getchar();
                }

                printf("Do u want to Update Book's Title\n");
                printf("Enter 'y' for Yes or 'n' for No: ");
                scanf("%c", &ch);
                getchar();
                if(ch == 'y'){
                    printf("Enter Book's new Title: ");
                    scanf("%[^\n]s", bk.title);
                    getchar();
                }
                
                printf("Do u want to Update Book's Author\n");
                printf("Enter 'y' for Yes or 'n' for No: ");
                scanf("%c", &ch);
                getchar();
                if(ch == 'y'){
                    printf("Enter new Author: ");
                    scanf("%[^\n]s", bk.author);
                    getchar();
                }
                
                printf("Do u want to Update Book's status\n");
                printf("Enter 'y' for Yes or 'n' for No: ");
                scanf("%c", &ch);
                getchar();
                if(ch == 'y'){
                    printf("Update Book Status: ");
                    scanf("%d", &bk.status);
                    getchar();
                }
            }
            fwrite(&bk, sizeof(bk), 1, fpW);
        }
        flag = 3;
    }

    if(deleting){
        while(fread(&bk, sizeof(bk), 1, fpR)){
            if(bk.bookId == bId){
                continue;
            }
            fwrite(&bk, sizeof(bk), 1, fpW);
        }
        flag = 4;
    }

    fclose(fpR);
    fclose(fpW);
    remove(booksFile);
    rename("temp.dat", booksFile);
    remove("temp.dat");

    // flag = 1 => successfully borrorwed book
    // flag = 2 => successfully returned book
    // flag = 3 => successfully modified member
    // flag = 4 => successfully deleted member
    // flag = 0 => no chnages or some error
    return flag;
}

void modifyMember(){
    int mId;
    printf("Enter Member Id: ");
    scanf("%d", &mId);
    getchar();

    // updateMemberFile(int modifiying, int deleteing, int borrwingBook, int returning, int mId, int bId)
    if(updateMemberFile(1, 0, 0, 0, mId, 0) == 3){
        printf("Member is modified successfully\n\n");
    }
    else{
        printf("Error! while modifying the memebr\n\n");
    }
}

void deleteMember(){
    int mId;
    printf("Enter Member Id: ");
    scanf("%d", &mId);
    getchar();

    // updateMemberFile(int modifiying, int deleteing, int borrwingBook, int returning, int mId, int bId)
    if(updateMemberFile(0, 1, 0, 0, mId, 0) == 4){
        printf("Member is deleted successfully\n\n");
    }
    else{
        printf("Error! while deleting the memebr\n\n");
    }
}

// ---------------------------------------------------------------------------------------------

void addBook(){
    FILE* fp = fopen(booksFile, "ab");
    if(fp == NULL){
        printf("Error! to open %s\n\n", booksFile);
        return;
    }

    struct Book bk;
    printf("Enter Book Id: ");
    scanf("%d", &bk.bookId);
    getchar();

    if(isBookExists(bk.bookId)){
        printf("Book is alreday exists\n\n");
        fclose(fp);
        return;
    }

    printf("Enter Book Title: ");
    scanf("%[^\n]s", bk.title);
    getchar();

    printf("Enter Book Author: ");
    scanf("%[^\n]s", bk.author);

    bk.status = 1;

    fwrite(&bk, sizeof(bk), 1, fp);
    fclose(fp);
    printf("Book is successfully added\n\n");
}

void displayBooks(){
    FILE* fp = fopen(booksFile, "rb");
    if(fp == NULL){
        printf("Error! to open %s\n", booksFile);
        return;
    }

    if(isFileEmpty(booksFile)){
        printf("%s is empty", booksFile);
        return;
    }

    struct Book bk;
    printf("Display all Books\n");
    printf("Book Id \t Title \t Author \t Status \n");
    while(fread(&bk, sizeof(bk), 1, fp)) {
        printf("%d\t", bk.bookId);
        printf("%s\t", bk.title);
        printf("%s\t", bk.author);
        printf("%d\n", bk.status);
    }
    printf("File ended\n\n");
    fclose(fp);
}

void searchBook(){
    FILE* fp = fopen(booksFile, "rb");
    if(fp == NULL){
        printf("Error! to open %s\n", booksFile);
        return;
    }

    int bId;
    printf("Enter book Id: ");
    scanf("%d", &bId);
    getchar();

    struct Book bk;
    while(fread(&bk, sizeof(bk), 1, fp)) {
        if(bId == bk.bookId){
            printf("Book founded\n");
            printf("Book Id \t Title \t Author \t Status \n");
            printf("%d\t", bk.bookId);
            printf("%s\t", bk.title);
            printf("%s\t", bk.author);
            printf("%d\n", bk.status);
            printf("\n\n");
            fclose(fp);
            return;
        }
    }

    printf("Book does not exists\n\n");
    fclose(fp);
}

void modifyBook(){
    int bId;
    printf("Enter Book Id: ");
    scanf("%d", &bId);
    getchar();

    if(isBookExists(bId) == 0){
        printf("Book is not exists\n\n");
        return;
    }

    // int updateBooksFile(int modifying, int deleting, int borrowing, int returning, int bId)
    if(updateBooksFile(1, 0, 0, 0, bId) == 3){
        printf("Book is modified successfully\n\n");
    }
    else{
        printf("Error! while modifying the book\n\n");
    }
}

void deleteBook(){
    int bId;
    printf("Enter Book Id: ");
    scanf("%d", &bId);
    getchar();

    if(isBookExists(bId) == 0){
        printf("Book is not exists\n\n");
        return;
    }

    // int updateBooksFile(int modifying, int deleting, int borrowing, int returning, int bId)
    if(updateBooksFile(0, 1, 0, 0, bId) == 4){
        printf("Book is deleted successfully\n\n");
    }
    else{
        printf("Error! while deleting the book\n\n");
    }
}

void borrowBook(){
    int mId;
    printf("Enter Member's Id: ");
    scanf("%d", &mId);
    //getchar();

    int bId;
    printf("Enter book id: ");

    scanf("%d", &bId);
    //getchar();

    //printf("inside the borrowBook()1\n");

    if(isMemeberExists(mId) == 0){
        printf("Member does not exists\n\n");
        return;
    }

    //printf("inside the borrowBook()2\n");

    if(isBookExists(bId) == 0){
        printf("Book does not exists\n\n");
        return;
    }

    //printf("inside the borrowBook()3\n");

    if(isBookAvailable(bId) == 0){
        printf("Book is not aviailabe for borrow\n\n");
        return;
    }

    //printf("inside the borrowBook()4\n");

    //printf("inside the borrowBook()5\n");
    // updateMemberFile(int modifiying, int deleteing, int borrwingBook, int returning, int mId, int bId)
    if(updateMemberFile(0, 0, 1, 0, mId, bId) == 1 && updateBooksFile(0, 0, 1, 0, bId) == 1){
        printf("Member borrowed book successfully\n\n");
    }
    else{
        printf("Error! while borrowing the book\n\n");
    }

    //printf("inside the borrowBook()6\n");
}

void returnBook(){
    int mId;
    printf("Enter Member's Id: ");
    scanf("%d", &mId);
    getchar();

    int bId;
    printf("Enter book's id: ");
    scanf("%d", &bId);
    getchar();

    if(isMemeberExists(mId) == 0){
        printf("Member does not exists\n\n");
        return;
    }

    if(isBookExists(bId) == 0){
        printf("Wrong Book Id. Book is not exists\n\n");
        return;
    }

    if(isBookAvailable(bId) == 1){
        printf("Book yet not borrowed\n\n");
        return;
    }

    // updateMemberFile(int modifiying, int deleteing, int borrwingBook, int mId, int bId)
    if(updateMemberFile(0, 0, 0, 1, mId, bId) == 2 && updateBooksFile(0, 0, 0, 1, bId) == 2){
        printf("Member returned book successfully\n\n");
    }
    else{
        printf("Member does not borrowed this book\n\n");
    }

}

void menuList(){
    printf("Library Management System\n\n");
    printf("Enter 0 for displaying the menu\n");
    printf("Enter 1 for adding a Book\n");
    printf("Enter 2 for adding a Member\n");
    printf("Enter 3 for displaying all Books\n");
    printf("Enter 4 for displaying all Members\n");
    printf("Enter 5 for searching a Book\n");
    printf("Enter 6 for searching a Member\n");
    printf("Enter 7 for modifying a Book\n");
    printf("Enter 8 for modifying a Member\n");
    printf("Enter 9 for deleting a Book\n");
    printf("Enter 10 for deleting a Member\n");
    printf("Enter 11 for borrowing a Book\n");
    printf("Enter 12 for returning a Book\n");
    printf("Enter -1 for exit\n\n");
}

void menu(){
    int option;
    int flag = 1;
    menuList();

    do{
        printf("Enter a option: ");
        scanf("%d", &option);
        switch (option)
        {
            case 0:
                menuList();
                break;

            case 1: 
                addBook();
                break;

            case 2: 
                addMember();
                break;
            
            case 3: 
                displayBooks();
                break;
            
            case 4: 
                displayMembers();
                break;
            
            case 5: 
                searchBook();
                break;
            
            case 6: 
                searchMember();
                break;
            
            case 7: 
                modifyBook();
                break;
            
            case 8: 
                modifyMember();
                break;
            
            case 9: 
                deleteBook();
                break;
            
            case 10: 
                deleteMember();
                break;
            
            case 11: 
                borrowBook();
                break;
            
            case 12: 
                returnBook();
                break;
            
            case -1:
                flag = 0;
                break;
        }    
    }while(flag);

}

int main() {
    menu();
}