package main

import (
	"fmt"
)

func main() {
	
	
	var revenu, expenses, taxRate = whatIs()
	var income , afterTax, ratio = calcularte(revenu,expenses,taxRate)
	yourIs(income, afterTax, ratio)

}

func whatIs()(revenu float64, expenses float64, taxRate float64){

	fmt.Print("what is your revenu : ")
	fmt.Scan(&revenu)

	fmt.Print("what is your expenses : ")
	fmt.Scan(&expenses)
	
	fmt.Print("what is your taxrate : ")
	fmt.Scan(&taxRate)
	
	return revenu, expenses, taxRate
}

func calcularte(revenu float64, expenses float64, taxRate float64) (income float64, afterTax float64, ratio float64){
	income = revenu - expenses
	afterTax = income * (1-taxRate/100)
	ratio = income / afterTax

	return income, afterTax, ratio	
}

func yourIs(income float64, afterTax float64, ratio float64){
	fmt.Printf("your income is : %.2f\n", income )
	fmt.Printf("your afterTax is : %.2f\n" ,afterTax)
	fmt.Printf("your ratio is : %.2f\n" , ratio)
}