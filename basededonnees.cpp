#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>

#include "basededonnees.h"

string nbToStr(int nombre)
{
    ostringstream a;
    a << nombre;
    return a.str();
}

int StrTonb(string texte)
{
   int nombre;
   istringstream iss( texte );
   iss >> nombre;
   return nombre;
}

void plusun(string &texte)
{
   int nombre;
   nombre=StrTonb(texte);
   nombre=nombre+1;
   texte=nbToStr(nombre);
}


static int callback(void *data, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}


 /*
 Table SIMULATIONIDENTIFICATION
 valeur : NOM,PRENOM,DEUXPRENOM,
 MENUAVECPARAMETRES,MENUSANSPARAMETRES,ID*/


        
        
int SQLBASE::isExist(){        
        int booleen=1;
       
        rc = sqlite3_open("chirurgie_endoluminale.db", &db);
         sql = "SELECT ID FROM SIMULATIONIDENTIFICATION WHERE PRENOM='"+prenom+"'AND NOM='"+nom+"' AND DEUXPRENOM='"+deuxprenom+"';";
        rc = sqlite3_prepare_v2( db,  sql.c_str(), -1, &stmt, NULL);

        do {
            rc = sqlite3_step(stmt);
            if ( rc == SQLITE_ROW) { //can read data
                id=(char *)sqlite3_column_text(stmt,0);
                
                } 
            
	    } while ( rc == SQLITE_ROW);
        
        if (id.empty()){
            booleen=0;
            //SQLid();
        }
        
        
        sqlite3_close( db);
    return booleen;
}    



/*string SQLBASE::SQLid(){

    rc = sqlite3_open("chirurgie_endoluminale.db", &db);
    sql = "SELECT COUNT(ID) FROM SIMULATIONIDENTIFICATION";
    rc = sqlite3_prepare_v2( db,  sql.c_str(), -1, &stmt, NULL);

    do {
		rc = sqlite3_step( stmt);
		if ( rc == SQLITE_ROW) {
		    id=(char *)sqlite3_column_text( stmt,0);
		    }
	    } while ( rc == SQLITE_ROW);
        plusun(id);
    
        sqlite3_close( db);
        return id;
    }*/



  
void SQLBASE::SQLinitialisation(string prenomprojet, string nomprojet, string deuxprenomprojet) {
        nom=nomprojet;
        prenom=prenomprojet;
        deuxprenom=deuxprenomprojet;
        
        isExist();

       
}
     


string SQLBASE::SQLcompteur(int menu){
            rc = sqlite3_open("chirurgie_endoluminale.db", &db);
            
                sql = "SELECT MENUAVECPARAMETRES FROM SIMULATIONIDENTIFICATION WHERE ID="+id;
                rc = sqlite3_prepare_v2( db,  sql.c_str(), -1, &stmt, NULL);

                do {
                    rc = sqlite3_step( stmt);
                    if ( rc == SQLITE_ROW) { //can read data
                        compteur=(char *)sqlite3_column_text( stmt,0);
                       
                    }  
                } while ( rc == SQLITE_ROW);

                sql = "SELECT MENUSANSPARAMETRES FROM SIMULATIONIDENTIFICATION WHERE ID="+id;
                rc = sqlite3_prepare_v2( db,  sql.c_str(), -1, &stmt, NULL);

                do {
                    rc = sqlite3_step( stmt);
                    if ( rc == SQLITE_ROW) { //can read data
                        compteur2=(char *)sqlite3_column_text( stmt,0);

                    } 
                } while ( rc == SQLITE_ROW);

            if (menu==1){
                if (compteur2.empty()){
                    compteur2="0";
                }
                if (compteur.empty()){ compteur="0";}
                plusun(compteur);

                sqlite3_close( db);
                return compteur;
            }
            
            
            if (menu==2){
                if (compteur.empty()){
                    compteur="0";
                }
                
                plusun(compteur2);
                 sqlite3_close( db);
                return compteur2;
            }
           
           
        
        }

string SQLBASE::getid(){
    return id;
}
string SQLBASE::getcompteur(int menu){
    if (menu==1){
        return compteur;
    }
    if (menu==2){
        return compteur2;
    }
    
}
void SQLBASE::SQLrequete(int menu){

    truesql="INSERT INTO SIMULATIONIDENTIFICATION(NOM,PRENOM,DEUXPRENOM,MENUAVECPARAMETRES,MENUSANSPARAMETRES) VALUES('";
    rc = sqlite3_open("chirurgie_endoluminale.db", &db);
    if (isExist()){
        if (menu==1){
            sql="UPDATE SIMULATIONIDENTIFICATION SET MENUAVECPARAMETRES="+compteur+" WHERE ID="+id+";";
        }
        if (menu==2){
            sql="UPDATE SIMULATIONIDENTIFICATION SET MENUSANSPARAMETRES="+compteur2+" WHERE ID="+id+";";
        }
    }
    else {
        sql=truesql+nom+"','"+prenom+"','"+deuxprenom+"',"+compteur+","+compteur2+");";
    }
    
    
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "requete done successfully\n");
   }
   sqlite3_close(db);
}


/* TABLE SIMULATIONDONNEES
valeurs : ID,AGE,FORMATION,ENDOSCOPE,TEMPS,POURCENTAGE ERREUR,TENTATIVE,TENTATIVE2
*/

void SQLBASE2::SQLinitialisation2( string ageprojet,string formationprojet, string niveauprojet, string endoscopeprojet){
            age=ageprojet;
            formation=formationprojet;
            niveau=niveauprojet;
            endoscope=endoscopeprojet;
           

        }

void SQLBASE2::SQLrecupererResults(string tempsprojet, string pourcentagerreurprojet){
          temps=tempsprojet;
          pourcentagerreur=pourcentagerreurprojet;
}

void SQLBASE2::SQLrecupererid(SQLBASE objet){
    if (objet.isExist()){
        id=objet.getid();
    }
   
}

void SQLBASE2::SQLrecupererCompteur(int menu, SQLBASE objet){
    if (menu==1){
        tentative=objet.getcompteur(menu);
        tentative2="0";
    }
    if (menu==2){
        tentative="0";
        tentative2=objet.getcompteur(menu);
    }
}

void SQLBASE2::SQLrequete2(){

    truesql="INSERT INTO SIMULATIONDONNEES(ID,AGE,FORMATION,NIVEAU,ENDOSCOPE,TEMPS,POURCENTAGEERREUR,TENTATIVEAVECPARAMETRES,TENTATIVESANSPARAMETRES) VALUES(";
    rc = sqlite3_open("chirurgie_endoluminale.db", &db);

    sql=truesql+id+","+age+",'"+formation+"','"+niveau+"','"+endoscope+"',"+temps+","+pourcentagerreur+","+tentative+","+tentative2+");";
    
    
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "requete done successfully\n");
   }
   sqlite3_close(db);
}





        int main(){
        string Prenom="Guigui", Nom="Deschamps", Prenom2="Remi", age="21", formation="ÉTUDIANTE", niveau="Novice", endoscope="MANUEL";
        
        SQLBASE objet;
        objet.SQLinitialisation(Prenom, Nom, Prenom2);
        objet.SQLcompteur(2);
        objet.SQLrequete(2);

        SQLBASE2 obj;
        obj.SQLinitialisation2(age,formation,niveau,endoscope);
        obj.SQLrecupererid(objet);
        obj.SQLrecupererCompteur(2,objet);
        obj.SQLrequete2();


        }



//creer string nom prenom deuxprenom
