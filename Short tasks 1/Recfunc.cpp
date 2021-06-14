
//recursive functions for tasks


//TASK_1

int recf1(int n){

	if (n < 1) return 0;

	return n + recf1(n - 1);
}


//TASK_2

int recf2(int n){
	
	if (n < 1) return 0;

	return n * n + recf2(n - 1);
}


//TASK_3

float recf3(float n){

	if (n < 1) return 0;

	return 1 / n + recf3(n - 1);
}


//TASK_4

float recf4(float n){

	if (n < 1) return 0;

	return 1 / (n*n) + recf4(n - 1);
}

//TASK_5

float recf5(float n, float k) {

	if (k < 0) return 0;

	return 1 / (n + k) + recf5(n, k - 1);

}

