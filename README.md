# 🖼️ Baby Photoshop - C++ Image Processing Tool

A comprehensive console-based image processing application developed in C++ that applies various filters and transformations to digital images. Built as part of the CS213 Object Oriented Programming course at FCAI, Cairo University.

## ✨ Features

- **15 Image Filters** — Complete suite of image manipulation algorithms
- **Multi-Format Support** — Works with JPEG, PNG, BMP, and other popular formats
- **Interactive Menu System** — User-friendly console interface for filter selection
- **Real-Time Processing** — Immediate visual feedback on filter applications
- **Safe File Handling** — Robust load/save with extension validation
- **Unsaved Changes Protection** — Prompts to save before loading new images or exiting

## 🎨 Filter Collection

### Core Filters (12)
| # | Filter | Description |
|---|--------|-------------|
| 1 | **Grayscale** | Converts RGB to single-channel intensity values |
| 2 | **Black & White** | Binary threshold conversion (0 or 255) |
| 3 | **Invert** | Photographic negative effect (255 - pixel value) |
| 4 | **Merge** | Combines two images with size handling options |
| 5 | **Flip** | Horizontal or vertical mirroring |
| 6 | **Rotate** | 90°, 180°, or 270° clockwise rotation |
| 7 | **Darken/Lighten** | 50% brightness adjustment in either direction |
| 8 | **Crop** | Extract rectangular regions with boundary validation |
| 9 | **Frame** | Add colored borders with customizable thickness |
| 10 | **Edge Detection** | Sobel-based boundary identification |
| 11 | **Resize** | Dimension scaling with ratio preservation |
| 12 | **Blur** | Configurable radius box blur algorithm |

### Bonus Filters — The Land of Wano (3)
| # | Filter | Description |
|---|--------|-------------|
| 13 | **Sunlight Enhancement** | Warm tone boost simulating natural sunlight |
| 15 | **Old TV Effect** | Retro CRT screen with scanline noise simulation |
| 16 | **Purple Tint** | Color grading with purple/magenta shift |

## 🏗️ Technical Architecture

### Class Structure
- **Image_Class** — External library for file I/O and pixel operations
- **Filter Functions** — 15 image transformation algorithms
- **Utility Layer** — Safe image loading/saving with validation
- **Menu Controller** — Interactive user interface loop

### Key Algorithms

**Merge Filter** — Intelligent dual-mode operation:
- Resize mode: Scales both images to maximum dimensions
- Crop mode: Merges overlapping common area only

**Edge Detection** — Multi-step process:
1. Grayscale conversion
2. Binary threshold (128)
3. 8-directional neighbor comparison
4. Edge pixel identification

**Blur Filter** — Box blur with configurable radius:
- O(r²) neighborhood averaging per pixel
- Boundary-safe pixel counting

## 🛡️ Validation & Error Handling

- **File Extension Verification** — Validates .jpg, .jpeg, .png, .bmp formats
- **Dimension Bounds Checking** — Prevents crop/resize operations outside image limits
- **Positive Integer Enforcement** — All size inputs validated > 0
- **Memory Warnings** — Alerts on potentially excessive dimensions (>10,000px)
- **Type Safety** — Character validation for menu selections (H/V, color choices)

## 🎓 Academic Context

- **Course:** CS213 — Object Oriented Programming
- **Institution:** Faculty of Computers and Artificial Intelligence, Cairo University
- **Academic Year:** 2025-2026
- **Team Size:** 3 members

### Team Contributions
| Member | ID | Filters Implemented |
|--------|----|---------------------|
| Ramez Rizk Hassan | 20240185 | 1, 4, 7, 10, 16 |
| Nour Khalaf Ahmed | 20240636 | 2, 5, 8, 11, 13 |
| Ahmed Yasser Nada | 20240824 | 3, 6, 9, 12, 15 |

## 🔧 Technical Specifications

| Aspect | Implementation |
|--------|---------------|
| Language | C++ (Standard 11+) |
| Image Library | stb_image / stb_image_write |
| Build System | Single-file compilation |
| Memory Model | Stack + Heap for image buffers |
| Pixel Format | RGB (3 channels, 8-bit per channel) |

## 🚀 Notable Implementation Details

- **Reverse Iteration Deletion** — Safe removal in merge operations
- **Ratio-Based Resizing** — Maintains aspect relationships during scaling
- **Neighbor-Averaging Blur** — Configurable kernel radius (1-15+)
- **Grayscale-to-Binary Pipeline** — Edge detection preprocessing
- **Dynamic Image Replacement** — Seamless current image updates after operations

---

Built with C++ 💻 | Console-based image processing power
