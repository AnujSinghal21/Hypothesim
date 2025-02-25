import { StrictMode } from 'react'
import { Route, Routes, BrowserRouter } from 'react-router-dom'
import Home from './Home'
import Build from './Build'
import Run from './Run'
import { createRoot } from 'react-dom/client'
import './index.css'
import 'bootstrap/dist/css/bootstrap.min.css';

createRoot(document.getElementById('root')).render(
  <StrictMode>
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/build" element={<Build />} />
        <Route path="/run" element={<Run />} />
      </Routes>
    </BrowserRouter>
  </StrictMode>,
)
