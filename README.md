# PA-Homework1

# 1. Walsh:
	Am impartit problema in 4 subprobleme. Ma intereseaza
	sa aflu de cate ori numarul care ne intereseaza apare in submatricea din
	dreapta jos. Pentru asta ma folosesc de parametrul inverted din functia recursiva
	recursive_call. La fiecare pas de recursivitate injumatatesc dimensiunea matricei matricei
	pe care o am initial, ajungand in final la matricea initiala ce contine doar elementul 0.
	Complexitate temporala: O(n * log(n));
	Complexitate temporala: O(1);

# 2. Statistics:
	La inceput calculez frecventa fiecarei litere din alfabet
	pentru fiecare cuvant citit. Folosesc o structura continuta dintr-un
	string, ce reprezinta cuvantul propriu-zis si un vector de frecventa
	de lungime maxima = 26, in care voi stoca frecventa fiecarei litere in cuvant.
	Urmatorul pas este sa sortez cuvintele in functie de diferenta intre frecventa literei
	curente in cuvant si de cate ori nu apare litera in cuvant. (2 * letter_freq - word.length).
	Pasul descris anterior se repeta pentru fiecare litera din alfabet.
	Dupa ce am efectuat sortarea adunam printr-un contor nr maxim de cuvinte pe care
	le putem concatena, astfel incat sa avem o litera dominanta.
	Complexitate temporala: O(26 * n * log(n)) -> sortarea, in final
	avem o complexitate temporala de O(n * L * log(n)), unde L este lungimea
	maxima pe care o poate avea un cuvant.
	Complexitate spatiala: O(n), deoarece retinem un vector de structuri Word,
	iar n este nr maxim de cuvinte pe care le putem avea.

# 3. Prinel:
	Ne creem un vector v care are lungimea maxima de max_target,
	unde max_target este cel mai mare numar din vectorul de targets.
	Vectorul v o sa retina numarul minim de operatii care trebuiesc aplicate pentru
	a ajunge la un anumit numar.
	Mai departe verificam un caz particular in care suma tuturor operatiilor ce trebuiesc
	aplicate este mai mica decat k. In caz afirmativ returnam suma punctelor pe care 
	le putem obtine. Altfel creem un vector pe care il initializam cu 0 la inceput si cu care
	calculam maximul punctelor pe care le putem obtine.
	Complexitate temporala: O(n * k);
	Complexitate temporala: O(k + max_target);

# 4. Crypto:
	Creem un vector v in care vom retine cate siruri se pot crea
	cu literele din cheie de la 0 la pasul curent. Urmeaza sa impartim problema in mai
	multe subprobleme. Pentru fiecare pereche de caractere din cele 2 siruri putem avea 3 posibilitati:
	Cand cele 2 caractere sunt egale le consideram ca fiind parte din solutie si continuam verificarea 
	pentru restul perechilor ramase. Cand caracterul din sirul k este semnul intrebarii, atunci
	numarul de siruri pe care le putem forma va fi egal cu dublul numarului de aractere dinstincte
	din sirul s adunat cu numarul de siruri pe care le puteam forma la pasul anterior. Cand cele 
	2 caractere nu sunt egale, ignoram caracterul din primul sir k si continuam verificarea pentru
	restul perechilor ramase.
	Complexitate temporala: O (l * n);
	Complexitate spatiala: O (l * n);

	
