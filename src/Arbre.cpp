/*
 * Arbre.cpp
 *
 *  Created on: 7 juin 2019
 *      Author: Toshiba
 */


#include <iostream>
#include "Noeud.h"
#include "Arbre.h"
#include <string.h>

template  <class T>
void Arbre<T> :: Placer ( Noeud<T>* pNode )
{
	// si le pNode est vide, on sort
	if ( !pNode )
		return;

	// si l arbre est vide, on lui copie cette branche
	if ( m_pTree == NULL )
	{
		m_pTree = pNode;
		return;
	}

	Noeud<T>* courant = m_pTree;
	Noeud<T>* precedent = NULL;

	// on se fraie un chemin a travers l arbre
	while ( courant )
	{
		precedent = courant;
		if ( pNode->valeur < courant->valeur )
			courant = courant->gauche;
		else
			courant = courant->droite;
	}
	// maintenant on demande aux branches precedentes de pointeur sur ce pNode
	if( pNode->valeur < precedent->valeur )
		precedent->gauche = pNode;
	else
		precedent->droite = pNode;
}


	//Ajoute une element a l arbre



template  <class T>
void Arbre<T> :: Ajouter ( T val )
{
	//	Alloue de la memoire pour un nouveau pNode
	Noeud<T>* tmp =  new Noeud<T>;
	// on ne sait pas encore sur quoi le pNode va pointer
	tmp->gauche = NULL;
	tmp->droite = NULL;
	// on lui copie la valeur
	tmp->valeur = val;
	// et l ajoute a l arbre
	Placer (tmp);
}


	//Renvoie un pointeur sur un element de l arbre qui est == a val


template <class T>
Noeud<T>* Arbre <T> :: Rechercher ( T val )
{
	Noeud<T>* curr = m_pTree;
	// on traverse l arbre
	while (curr)
	{
		// si ce pNode a la bonne valeur, on a trouvé
		if(curr->valeur == val)
			return curr;
		// sinon, on sait si le pNode qu on cherche est plutot vers la gauche ou vers la droite
		// car lorsqu on a construit l arbre, on l a organisé de maniere a ce que les valeurs
		// plus petites soient vers la gauche et les plus garndes vers la droite
		if (val < curr->valeur)
			curr = curr->gauche;
		else
			curr = curr->droite;
	}

	// rien trouvé
	return NULL;
}


//	Supprime une pNode de l arbre
	//On peut obtenir un pointeur sur un pNode via la methode Rechercher(...);



template<class T>
void Arbre<T> :: Supprimer( Noeud<T>* pNode )
{
	// si le noeud est vide, on sort
	if ( !pNode )
		return;

	// on sauvegarde des valeurs
	Noeud<T>* droite = pNode->droite;
	Noeud<T>* gauche = pNode->gauche;
	Noeud<T>* courant = m_pTree;

	// Cas délicat : si on supprime la racine?
	if( pNode == m_pTree )
	{
		// la valeur superieur est toujours a droite
		m_pTree = droite;
		// mais il ne faut pas oublier celle de gauche
		if( gauche )
			Placer( gauche );
		// on vire la racine et on sort
		delete pNode;
		return;
	}

	// on traverse tout l arbre
	while( courant )
	{
		// si une des feuilles de ce noeud est celle qu on cherche, on sort
		if(	courant->droite == pNode || courant->gauche == pNode )
			break;

		// sinon, on traverse
		if( pNode->valeur >= courant->valeur )
			courant = courant->droite;
		else
			courant = courant->gauche;
	}

	if( courant->droite == pNode )
		courant->droite = droite;
	else
		courant->gauche = droite;

	// Et puis on replace l'autre fils du pNode disparu
	if( gauche )
		Placer( gauche );

	// Enfin, on libère l'objet pNode de ses obligations
	delete pNode;
}


/*	Fonction qui affiche l arbre
	un operateur << est necessaire
	mise en globale, et non pas en methode de classe car
	elle n est pas necessaire a la gestion de l arbre et pas très utile
*/


template <class T>
void Afficher ( Noeud<T> *pNode )
{
	// on traverse vers la gauche (valeurs inferieures), si il existe
	if ( pNode->gauche )
		Afficher (pNode->gauche);
	// on affiche le noeud en cours
	if ( pNode )
		std::cout << pNode->valeur << "\n";
	// et traverse vers la droite (valeurs superieurs)
	if ( pNode->droite )
		Afficher (pNode->droite);
}


