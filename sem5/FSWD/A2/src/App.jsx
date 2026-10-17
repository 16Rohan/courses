import { NavLink, Routes, Route, Navigate } from "react-router-dom";
import LiveSearch from "./pages/LiveSearch";
import Dashboard from "./pages/Dashboard";
import MarksEntry from "./pages/MarksEntry";

function App() {
	return (
		<div className="app">
			<header className="navbar">
				<div className="brand">FSWD Assignment 2: 1602-24-733-036</div>

				<nav>
					<NavLink to="/search">Q1: Live Search</NavLink>
					<NavLink to="/dashboard">Q2: Dashboard</NavLink>
					<NavLink to="/marks">Q3: Marks Entry</NavLink>
				</nav>
			</header>

			<main className="container">
				<Routes>
					<Route path="/" element={<Navigate to="/search" />} />
					<Route path="/search" element={<LiveSearch />} />
					<Route
						path="/dashboard"
						element={
							<Dashboard isLoggedIn={true} userName="Rohan" role="student" />
						}
					/>
					<Route path="/marks" element={<MarksEntry />} />
				</Routes>
			</main>

			<footer className="footer">React Practical Assignments</footer>
		</div>
	);
}

export default App;
