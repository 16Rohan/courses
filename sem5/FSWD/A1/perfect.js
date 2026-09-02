const readline = require("readline");

const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

rl.question("Enter a number: ", function (input) {
	var num = parseInt(input);
	var sum = 0;

	for (var i = 1; i < num; i++) {
		if (num % i == 0) {
			sum = sum + i;
		}
	}

	if (sum == num) {
		console.log(num + " is a Perfect number.");
	} else {
		var nearest = num - 1;
		var found = false;

		while (nearest > 0) {
			var total = 0;

			for (var j = 1; j < nearest; j++) {
				if (nearest % j == 0) {
					total = total + j;
				}
			}

			if (total == nearest) {
				found = true;
				break;
			}

			nearest--;
		}

		console.log(num + " is not a Perfect number.");

		if (found) {
			console.log(
				"Nearest Perfect number less than " + num + " is " + nearest + ".",
			);
		} else {
			console.log("There is no Perfect number less than " + num + ".");
		}
	}

	rl.close();
});

