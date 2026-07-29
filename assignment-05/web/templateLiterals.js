const users = [
    { name: "Alice", age: 53 },
    { name: "Tim", age: 74 }
];

function generateTable() {
    const body = document.getElementsByTagName("body")[0];
    const table = document.createElement("table");

    const rows = users.map(user => {
        return `
        <tr>
            <td>${user.name}</td>
            <td>${user.age}</td>
        </tr>
    `;
    });

    rows.forEach(row => table.innerHTML += row);

    body.appendChild(table);
}

generateTable();