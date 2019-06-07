/*
 * Arbre.h
 *
 *  Created on: 7 juin 2019
 *      Author: Toshiba
 */



#ifndef ARBRE_H_
#define ARBRE_H_
#include <iostream>
#include "Noeud.h"


template<class T>
class Arbre
{
public:

		//Constructeur




	Arbre (){
		m_pTree = NULL;
	}


		//Methodes utiles




	void Ajouter (T val);
	Noeud<T>* Rechercher (T val);
	void Supprimer(Noeud<T>* pNode);


		//Accesseurs




	Noeud<T>* root(){
		// renvoie un pointeur sur le pNode de base
		return m_pTree;
	}
private:
	// fonction privée car non nécessaire
	void Placer (Noeud<T> *pNode);

	Noeud<T>* m_pTree;
};








#endif /* ARBRE_H_ */
