Loan Prolog
:- initialization(main).

% Facts
min_income(30000).
min_cred_score(650).
max_debt_to_income_ratio(0.4).

interest_rate(home_loan, 6.50).
interest_rate(home_loan, 8.50).

%Rules
income_eligible(Income):-
  min_income(MinIncome),
  Income >= MinIncome.
 
cred_score_eligible(CredScore):-
  min_cred_score(MinCredScore),
  CredScore >= MinCredScore.
 
debt_to_income_eligible(Income, Debt):-
  max_debt_to_income_ratio(MaxRatio),
  Ratio is Debt / Income,
  Ratio =< MaxRatio.
 
loan_eligible(Income, CredScore, Debt, EmploymentStatus):-
  income_eligible(Income),
  cred_score_eligible(CredScore),
  debt_to_income_eligible(Income, Debt),
  EmploymentStatus = employed.
 
calculate_emi(Amount, Tenure, Rate, EMI):-
  MonthlyRate is Rate / (12*100),
  PowerFactor is (1 + MonthlyRate) ** Tenure,
  EMI is (Amount * MonthlyRate * PowerFactor) / (PowerFactor - 1).

main :-
read(Income),
read(CredScore),
read(Debt),
read(EmploymentStatus),

( loan_eligible(Income, CredScore, Debt, EmploymentStatus) ->
  write('Eligible for loan.'), nl,
  read(LoanType),
  read(Amount),
  read(Tenure),
  interest_rate(LoanType, InterestRate),
  calculate_emi(Amount, Tenure, InterestRate, EMI),
  write('EMI: '), write(EMI), nl;
  write('Not eligible for loan.'), nl
).
50000.
700.
10000.
employed.
home_loan.
200000.
120.
