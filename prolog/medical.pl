% Start program
:- initialization(main).

% Patient's symptoms (change these facts to simulate input)
symptom(fever).
symptom(headache).
symptom(body_ache).
symptom(chills).


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
    findall(D, disease(D), Diagnoses),
    ( Diagnoses = [] ->
        write('No matching disease found.')
    ; print_diagnoses(Diagnoses)
    ),
    halt.

% Print result
print_diagnoses([]).
print_diagnoses([H|T]) :-
    format('Possible diagnosis: ~w~n', [H]),
    print_diagnoses(T).
