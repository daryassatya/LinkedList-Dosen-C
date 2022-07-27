 // Linked list operations in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <conio.h>
#include <iostream>

// Create a node
char kode[12], nama[50];
int sks;

struct Node {
	char kode_dosen[12], nama_dosen[50];
    int sks_dosen, data;
    
    struct Node* next;
};


char menu(){
	char pilihan;
	
	printf("----------PROGRAM DATA DOSEN----------\n");
	printf("1.	Input Data Dosen Baru\n");
	printf("2.	Cari Data Dosen Berdasarkan nama\n");
	printf("3.	Hapus Data  Dosen Berdasarkan Kode Dosen\n");
	printf("4.	Tampilkan Data Dosen Berdasarkan SKS Terbanyak\n");
	printf("5.	Tampilkan Data Dosen Berdasarkan SKS Tersedikit\n");
	printf("6.	Tampilkan Rata-rata Total SKS Dosen\n");
	printf("7.	Tampilkan Seluruh Data Dosen Beserta Jumlah Data Yang Tersimpan Dalam List\n");
	printf("8.	Keluar\n\n");
	printf("Pilihan: ");
	scanf(" %c", &pilihan);
	return pilihan;
}



// Insert the the end
void insertAtEnd(struct Node** head_ref, char *kode, char *nama, int sks) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; /* used in step 5*/

    strcpy(new_node->kode_dosen, kode);
    strcpy(new_node->nama_dosen, nama);
    new_node->sks_dosen = sks;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) last = last->next;

    last->next = new_node;
    return;
}

// Delete a node
void deleteNode(struct Node** head_ref, char *kode) {
    struct Node *temp = *head_ref, *prev;
	if(temp == NULL){
		printf("Data Masih Kosong!");
	} else {
		
		if (temp != NULL && strcmp(temp->kode_dosen, kode) == 0) {
        	*head_ref = temp->next;
        	free(temp);
        	printf("Data Dengan Kode %s Telah Dihapus!", kode);
        	return;
    	}
    	// Find the key to be deleted
    	while (temp != NULL && strcmp(temp->kode_dosen, kode) != 0) {
        	prev = temp;
        	temp = temp->next;
    	}

    	// If the key is not present
    	if (temp == NULL) {
    		printf("Data Tidak Ditemukan!!");
    		return;
		}

    	// Remove the node
    	prev->next = temp->next;

    	free(temp);
    	printf("Data Dengan Kode %s Telah Dihapus!", kode);
	}
}

// Search a node
int searchNode(struct Node** head_ref, char *nama) {
    struct Node* current = *head_ref;
	int i=0;
	int status = 0;
	if(current == NULL){
		printf("Data Dosen Masih Kosong!\n");
	} else {
		while (current != NULL) {
    		i++;
    		if (strcmp(current->nama_dosen, nama) == 0){
    			status++;
    			printf("------------------------------------------\n");
    			printf("Data Ke-%d \n", i);
    			printf("Kode Dosen : %s\n", current->kode_dosen);
				printf("Nama Dosen : %s\n", current->nama_dosen);
				printf("SKS Dosen : %d\n", current->sks_dosen);
				printf("------------------------------------------\n");
				break;
			} else{
        		current = current->next;
    		}
		}
		if(status == 0){
			printf("Dosen Dengan Nama %s Tidak Ditemukan!", nama);
		}
	}
}

//Less SKS
int sksTerkecil(struct Node** head_ref){
	struct Node* current = *head_ref;
	int tempSks = 500;
	if(current == NULL){
		return 999;
	} else {
		while (current != NULL) {
    		if (current->sks_dosen < tempSks){
				tempSks = current->sks_dosen;
			} 
        	current = current->next;
		}
		
	}
	return tempSks;
}

//More SKS
int sksTerbesar(struct Node** head_ref){
struct Node* current = *head_ref;
	int tempSks = 0;
	if(current == NULL){
		return 999;
	} else {
		while (current != NULL) {
    		if (current->sks_dosen > tempSks){
				tempSks = current->sks_dosen;
			} 
        	current = current->next;
		}
		
	}
	return tempSks;
}

//FindSks
void findSks(struct Node** head_ref, int sks, char *statusCom){
	struct Node* current = *head_ref;
	int i=0;
	int status = 0;
	if(sks == 999){
		printf("Data Dosen Masih Kosong!\n");
	} else {
		while (current != NULL) {
    		i++;
    		if (current->sks_dosen == sks){
    			status++;
    			printf("---------- SKS Dosen %s ----------\n", statusCom);
    			printf("Data Ke-%d \n", i);
    			printf("Kode Dosen : %s\n", current->kode_dosen);
				printf("Nama Dosen : %s\n", current->nama_dosen);
				printf("SKS Dosen : %d\n", current->sks_dosen);
				printf("------------------------------------------\n");
				break;
			} else{
        		current = current->next;
    		}
		}
		if(status == 0){
			printf("Dosen Dengan Nama %s Tidak Ditemukan!", nama);
		}
	}
}


//Average
void sksRata(struct Node** head_ref){
	struct Node* current = *head_ref;
	int jumlah = 0;
	int i = 0;
	float rata;
	
	if(current == NULL){
		printf("Data Dosen Masih Kosong!");
	} else {
		while (current != NULL) {
    		i++;
    		jumlah = jumlah + current->sks_dosen;
        	current = current->next;
		}
		printf("Rata-rata SKS Dosen : %d", (jumlah/i));        
    	printf("\n");
	}
}

// Print the linked list
void printList(struct Node* node) {
	int total = 0;
	if(node == NULL){
		printf("Data Dosen Masih Kosong!");
	} else {
		printf("--- Daftar Data Dosen ---\n");
		printf("------------------------------------------\n");
	
    	while (node != NULL) {
    		total++;
    		printf("Data Ke-%d\n", total);
       		printf("Kode Dosen : %s\n", node->kode_dosen);
			printf("Nama Dosen : %s\n", node->nama_dosen);
			printf("SKS Dosen : %d\n", node->sks_dosen);
			printf("------------------------------------------\n");
        	node = node->next;
    	}
    	printf("Total Data Dosen : %d", total);
    }
}

// Driver program
int main() {
	char pilihan;
    struct Node* head = NULL;
   
    do{
    	system("cls");
		char pilihan;
	
		pilihan = menu();
		fflush(stdin);
		
		switch(pilihan){
			case '1':
				printf("=====Insert Data Dosen=====\n");
				printf("Kode Dosen : ");
				gets(kode);
				printf("Nama Dosen : ");
				gets(nama);
				printf("SKS Dosen : ");
				scanf(" %d", &sks);
			
				insertAtEnd(&head, kode, nama, sks);
				printf("Data Berhasil Ditambahkan!");
				break;
			case '2':
				printf("Masukkan Nama Dosen Yang Ingin Dicari : ");
				gets(nama);
				searchNode(&head, nama);
				break;
			case '3':
				printf("Masukkan Kode Dosen Yang Ingin Dihapus : ");
				gets(kode);
				deleteNode(&head, kode);
				break;
			case '4':
				findSks(&head, sksTerbesar(&head), "TERBESAR");
				break;
			case '5':
				findSks(&head, sksTerkecil(&head), "TERKECIL");
				break;
			case '6':
				sksRata(&head);
				break;
			case '7':
				printList(head);
				break;
			case '8':
				printf("Terimakasih Terlah Menggunakan Aplikasi Ini!");
				return 0;
				break;
			default:
				printf("Tidak Ada Pilihan Seperti Itu!");
				break;
		}
		getch();
	} while (pilihan != '8');
	return 0;
}
