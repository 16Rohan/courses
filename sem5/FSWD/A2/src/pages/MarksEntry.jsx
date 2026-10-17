import { useState } from "react";

function MarksEntry() {
	const [studentName, setStudentName] = useState("");
	const [marks, setMarks] = useState(["", "", "", "", ""]);
	const [message, setMessage] = useState("");

	const maxMarks = [10, 10, 15, 15, 20];

	const total = marks.reduce((sum, mark, index) => {
		const value = Number(mark);

		if (mark === "" || value < 0 || value > maxMarks[index]) {
			return sum;
		}

		return sum + value;
	}, 0);

	function handleChange(index, value) {
		const updatedMarks = [...marks];
		updatedMarks[index] = value;
		setMarks(updatedMarks);
		setMessage("");
	}

	function handleSubmit(e) {
		e.preventDefault();

		if (!studentName.trim()) {
			setMessage("Please enter the student name.");
			return;
		}

		for (let i = 0; i < marks.length; i++) {
			if (
				marks[i] === "" ||
				Number(marks[i]) < 0 ||
				Number(marks[i]) > maxMarks[i]
			) {
				setMessage(`Please enter valid marks for Question ${i + 1}.`);
				return;
			}
		}

		setMessage(`Marks submitted successfully! Total: ${total}`);
	}

	function handleReset() {
		setStudentName("");
		setMarks(["", "", "", "", ""]);
		setMessage("");
	}

	return (
		<section>
			<h1 className="page-title">Question 3: Marks Entry</h1>
			<p className="subtitle">
				Develop a React web application that allows a faculty member to enter
				students' marks question-wise for a subject. Validate each entry against
				the maximum marks of that question (show error messages), compute the
				total automatically, and provide Submit and Reset buttons.
			</p>

			<form className="card" onSubmit={handleSubmit}>
				<label htmlFor="studentName">Student Name</label>
				<input
					id="studentName"
					className="field"
					type="text"
					placeholder="Enter student name"
					value={studentName}
					onChange={(e) => setStudentName(e.target.value)}
				/>

				<div className="marks-row">
					<strong>Question</strong>
					<strong>Maximum Marks</strong>
					<strong>Marks Obtained</strong>
				</div>

				{maxMarks.map((max, index) => (
					<div key={index}>
						<div className="marks-row">
							<label htmlFor={`q${index}`}>
								{["FSWD", "CN", "AI", "IoT", "SDC"][index]}
							</label>

							<span>{max}</span>

							<input
								id={`q${index}`}
								className="field"
								type="number"
								min="0"
								max={max}
								step="any"
								placeholder="Enter marks"
								value={marks[index]}
								onChange={(e) => handleChange(index, e.target.value)}
							/>
						</div>

						{marks[index] !== "" &&
							(Number(marks[index]) < 0 || Number(marks[index]) > max) && (
								<p className="error">Enter marks between 0 and {max}.</p>
							)}
					</div>
				))}

				<p className="total">
					Total: {total} / {maxMarks.reduce((sum, mark) => sum + mark, 0)}
				</p>

				{message && (
					<p
						className={
							message.startsWith("Marks submitted") ? "success" : "error"
						}
					>
						{message}
					</p>
				)}

				<button className="button primary" type="submit">
					Submit
				</button>

				<button
					className="button secondary"
					type="button"
					onClick={handleReset}
				>
					Reset
				</button>
			</form>
		</section>
	);
}

export default MarksEntry;
