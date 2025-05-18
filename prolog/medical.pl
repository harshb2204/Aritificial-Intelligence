% Start program
:- dynamic(symptom/1).
:- initialization(main).

% Diagnosis rules
disease(flu) :-
	symptom(fever),
	symptom(headache),
	symptom(body_ache),
	symptom(chills).

disease(cold) :-
	symptom(cough),
	symptom(sneezing),
	symptom(runny_nose).

disease(covid) :-
	symptom(fever),
	symptom(dry_cough),
	symptom(loss_of_taste_or_smell),
	symptom(fatigue).

% Main predicate
main :-
    % Read symptoms from user
    read(SymptomList),
    assert_symptoms(SymptomList),

    findall(D, disease(D), Diagnoses),
	( Diagnoses = [] ->
    	write('No matching disease found.'), nl
	; print_diagnoses(Diagnoses)
	),
	halt.

% Assert all symptoms
assert_symptoms([]).
assert_symptoms([H|T]) :-
    assertz(symptom(H)),
    assert_symptoms(T).

% Print result
print_diagnoses([]).
print_diagnoses([H|T]) :-
	format('Possible diagnosis: ~w~n', [H]),
	print_diagnoses(T).
    [fever, headache, body_ache, chills].