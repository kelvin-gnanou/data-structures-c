
# 📚 Structure de donnée en c

[![Status](https://img.shields.io/badge/status-in%20development-orange)]()
[![Language](https://img.shields.io/badge/language-C%20%7C%20C%2B%2B-blue)]()
[![License](https://img.shields.io/badge/license-MIT-green)]()
[![Focus](https://img.shields.io/badge/focus-data%20structures%20%26%20algorithms-purple)]()

> Implémentation progressive de structures de données fondamentales en **C**, avec une approche pédagogique, modulaire et orientée qualité logicielle.

---

## ✨ À propos du projet

Ce dépôt a été conçu pour construire une base technique solide autour des structures de données classiques.

L’objectif n’est pas seulement d’“implémenter du code”, mais de :

- comprendre le comportement interne des structures de données,
- travailler le bas niveau avec rigueur,
- renforcer la maîtrise de la mémoire, des pointeurs et de l’organisation modulaire,
- produire du code lisible, maintenable et évolutif,
- préparer des bases sérieuses pour des projets plus avancés en algorithmique, systèmes et IA.

Chaque structure est isolée dans son propre dossier avec :
- ses fichiers d’en-tête,
- ses sources,
- son programme de démonstration,
- son `Makefile`.

---

## 🧠 Objectifs pédagogiques

Ce projet sert à développer les réflexes suivants :

- penser en termes de structure, pas seulement de syntaxe,
- séparer proprement interface et implémentation,
- écrire du code simple avant de le rendre plus avancé,
- mesurer la complexité des opérations,
- comprendre les compromis entre performance, lisibilité et maintenabilité,
- adopter une logique d’ingénierie logicielle, pas juste de “code qui marche”.

---

## 🧩 Structures disponibles

### `basic_queue`

Implémentation d’une file simple.

Fonctionnalités visées :
- insertion en file,
- suppression en tête,
- consultation de l’état de la file,
- affichage de démonstration.

### `stack`

Implémentation d’une pile.

Fonctionnalités visées :
- empilement,
- dépilement,
- lecture du sommet,
- vérification de vacuité.

### `linked-list`

Implémentation d’une liste chaînée.

Fonctionnalités visées :
- insertion,
- suppression,
- parcours,
- manipulation de nœuds.

### `binary-tree`

Implémentation d’un arbre binaire.

Fonctionnalités visées :
- insertion,
- parcours,
- recherche,
- base pour des améliorations futures : arbre de recherche, suppression avancée, équilibrage.

---


## ▶️ Comment exécuter

Chaque structure est indépendante:

```bash
cd stack
make
make run
```

---

## 🗂️ Structure du dépôt

```bash
data-struct.git/
├── .gitignore
├── LICENSE
├── README.md
├── basic_queue
│   ├── include
│   │   └── queue.h
│   ├── makefile
│   └── src
│       ├── main.c
│       └── queue.c
├── binary-tree
│   ├── include
│   │   └── binary_tree.h
│   ├── makefile
│   └── src
│       ├── binary_tree.c
│       └── main.c
├── linked-list
│   ├── include
│   │   └── list.h
│   ├── makefile
│   └── src
│       ├── list.c
│       └── main.c
└── stack
    ├── include
    │   └── stack.h
    ├── makefile
    └── src
        ├── main.c
        └── stack.c
```

## 🛠️ Technologies utilisées

C · Makefile · clang · Git

---

## ⚙️ Design Principles

- Architecture modulaire
- Séparation claire des responsabilités
- Gestion explicite de la mémoire
- Conception de composants réutilisables

---

## 📌 Que démontre ce projet

- Développement des principales structures de données sans bibliothèques spécialisées
- Compréhension approfondie des pointeurs et de la gestion mémoire
- Conception modulaire d’applications en C
- Production d’un code lisible, robuste et facile à maintenir

---

## 🚀 Améliorations futures

- Mise en place d’un framework de tests unitaires
- Réalisation de benchmarks de performance
- Amélioration de la gestion des erreurs
- Extension des API pour chaque structure de données

---

## 📈 Vision

Un projet fondamental destiné à évoluer vers la programmation système, l’ingénierie backend et la maîtrise approfondie des algorithmes.

---

## 📄 Licence

Licence MIT — libre d’utilisation, de modification et de distribution.
