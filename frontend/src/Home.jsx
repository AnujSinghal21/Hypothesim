import { React } from 'react'
import NavBar from './Components/NavBar'
const Home = () => {
    return (
        <>
            <div>
                <NavBar />
                <div>
                <div className="container-fluid">
                    <h1 className="display-4 my-2 mx-3">Hypothesim</h1>
                    <p className="lead mx-3">Simulating the Future, Testing the Unknown</p>
                </div>

                <section id="about" className="container-fluid text-center py-5">
                    <h2>About Hypothesim</h2>
                    <p className="text-muted">Hypothesim is a world simulator designed for game-theoretic and genetic simulations, enabling predictive analysis and hypothesis testing.</p>
                </section>

                <section id="features" className="container py-5">
                    <h2 className="text-center">Key Features</h2>
                    <div className="row text-center mt-4">
                        <div className="col-md-4">
                            <div className="card p-3 shadow">
                                <h5>Game Theory Simulations</h5>
                                <p className="text-muted">Run strategic decision-making models with dynamic interactions.</p>
                            </div>
                        </div>
                        <div className="col-md-4">
                            <div className="card p-3 shadow">
                                <h5>Genetic Evolution Modeling</h5>
                                <p className="text-muted">Simulate genetic algorithms and evolution-based scenarios.</p>
                            </div>
                        </div>
                        <div className="col-md-4">
                            <div className="card p-3 shadow">
                                <h5>Predictive Analysis</h5>
                                <p className="text-muted">Forecast outcomes based on complex simulations to test predictions</p>
                            </div>
                        </div>
                    </div>
                </section>

                <section id="team" className="container text-center py-5">
                    <h2>Meet the Developers</h2>
                    <div className="row mt-4">
                        <div className="col-md-4">
                            <div className="card p-3 shadow">
                                <h5>Devansh Ojha</h5>
                                <p className="text-muted">AI Enthusiast | Optimization Expert</p>
                            </div>
                        </div>
                        <div className="col-md-4">
                            <div className="card p-3 shadow">
                                <h5>Anuj Singhal</h5>
                                <p className="text-muted">Software Engineer | Game Theory Specialist</p>
                            </div>
                        </div>
                        <div className="col-md-4">
                            <div className="card p-3 shadow">
                                <h5>Rohan Phad</h5>
                                <p className="text-muted">Full-Stack Developer</p>
                            </div>
                        </div>
                    </div>
                </section>

                <footer className="bg-dark text-white text-center py-3">
                    <p>© 2025 Hypothesim. All Rights Reserved.</p>
                </footer>

                </div>
            </div>
        </>
    )
}

export default Home;
