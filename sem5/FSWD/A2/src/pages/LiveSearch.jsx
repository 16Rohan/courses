import { useState } from "react";

function LiveSearch() {
	const [search, setSearch] = useState("");

	const names = [
		"Abhinav",
		"Areej",
		"Akshara",
		"Akshay",
		"Anjana",
		"Aravind", 
		"Pavan",
		"Bharath", 
		"Bhavishya", 
		"Bhuvan"
	];

	const filteredNames = names.filter((name) =>
		name.toLowerCase().includes(search.toLowerCase()),
	);

	return (
		<section>
			<h1 className="page-title">Question 1: Live Search</h1>
			<p className="subtitle">React code to create a live search box: render a list of at least ten names using map() with a unique key, and filter the list as the user types in a controlled input field (onChange event handler).</p>

			<div className="card">
				<label htmlFor="search">Search by name</label>

				<input
					id="search"
					className="field"
					type="text"
					placeholder="Type a name..."
					value={search}
					onChange={(e) => setSearch(e.target.value)}
				/>

				<ul className="name-list">
					{filteredNames.map((name) => (
						<li key={name}>{name}</li>
					))}
				</ul>

				{filteredNames.length === 0 && <p>No matching names found.</p>}
			</div>
		</section>
	);
}

export default LiveSearch;
