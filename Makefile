compile:
	@gcc -o prog *.c && clear && echo "Executable mis à jour avec succès !"

run:
	@./prog && clear 

clean:
	@rm -f ./prog && clear && echo "Executable supprimé avec succès !"