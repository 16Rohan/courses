import { useState } from "react";

function Dashboard({ userName }) {
	const [isLoggedIn, setIsLoggedIn] = useState(true);
	const [role, setRole] = useState("student");

	return (
		<section>
			<h1 className="page-title">Question 2: Dashboard</h1>
			<p className="subtitle">
            React code to create a Dashboard component that uses props and conditional rendering: if isLoggedIn is true show a welcome message with the user's role (admin / student) and role-specific options, otherwise show a Login button. Use the ternary operator and the && operator in JSX.
			</p>

			<div className="card">
				<h3>Test Dashboard</h3>

				<button
					className="button primary"
					onClick={() => {
						setIsLoggedIn(true);
						setRole("student");
					}}
				>
					Student
				</button>

				<button
					className="button primary"
					onClick={() => {
						setIsLoggedIn(true);
						setRole("admin");
					}}
				>
					Admin
				</button>

				<button
					className="button secondary"
					onClick={() => setIsLoggedIn(false)}
				>
					Logged Out
				</button>

				<hr />

				{isLoggedIn ? (
					<>
						<h2>Welcome, {userName}!</h2>
						<p>
							Your role is: <strong>{role}</strong>
						</p>

						{role === "admin" && (
							<ul className="role-options">
								<li>Manage Students</li>
								<li>Manage Faculty</li>
								<li>View Reports</li>
							</ul>
						)}

						{role === "student" && (
							<ul className="role-options">
								<li>View Marks</li>
								<li>View Attendance</li>
								<li>View Timetable</li>
							</ul>
						)}
					</>
				) : (
					<div>
						<h2>You are not logged in</h2>
						<button
							className="button primary"
							onClick={() => {
								setIsLoggedIn(true);
								setRole("student");
							}}
						>
							Login
						</button>
					</div>
				)}
			</div>
		</section>
	);
}

export default Dashboard;
