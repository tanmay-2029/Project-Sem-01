Income Tax Calculator (FY 2025–26)

A **C program** that calculates **individual income tax** based on the **New Tax Regime (FY 2025–26)** as per Indian income tax rules.

This project demonstrates:

* Slab-wise tax calculation
* Standard deduction
* Section 87A rebate
* Marginal relief
* Surcharge for high-income earners
* Health & Education Cess

---

## Features

*  Uses **latest tax slabs (FY 2025–26 – New Regime)**
*  Applies **₹75,000 standard deduction**
*  Handles **rebate under Section 87A**
*  Implements **marginal relief (₹12L – ₹12.75L)**
*  Calculates **surcharge for high-income individuals**
*  Adds **4% Health & Education Cess**
*  Well-structured, readable, and documented C code

---

##  Tax Slabs Used (New Regime)

| Net Taxable Income (₹) | Tax Rate |
| ---------------------- | -------- |
| Up to 4,00,000         | NIL      |
| 4,00,001 – 8,00,000    | 5%       |
| 8,00,001 – 12,00,000   | 10%      |
| 12,00,001 – 16,00,000  | 15%      |
| 16,00,001 – 20,00,000  | 20%      |
| 20,00,001 – 24,00,000  | 25%      |
| Above 24,00,000        | 30%      |

---

##  Other Rules Implemented

* **Standard Deduction**: ₹75,000
* **Maximum Rebate (Sec 87A)**: ₹60,000 (Income ≤ ₹12L)
* **Marginal Relief**: Available up to ₹12.75L
* **Health & Education Cess**: 4%
* **Surcharge**:

  * ₹50L – ₹1Cr → 10%
  * ₹1Cr – ₹2Cr → 15%
  * ₹2Cr – ₹5Cr → 25%
  * Above ₹5Cr → 25% (capped in new regime)

---

## How the Program Works

1. Takes **annual income** as input
2. Applies **standard deduction**
3. Calculates **slab-wise tax**
4. Adds **surcharge** if applicable
5. Applies **rebate or marginal relief**
6. Adds **4% cess**
7. Outputs **final tax payable**

---

## Flowchart

*| Annual Income |
        ↓
*| Standard Deduction (₹75,000) |
        ↓
*| Net Taxable Income |
        ↓
*| Slab-wise Tax Calculation |
        ↓
*| Surcharge (if applicable) |
        ↓
*| Rebate / Marginal Relief |
        ↓
*| Add 4% Cess |
        ↓
*| Final Tax Payable |

---

##  Compile and Run

### Compile

```bash
gcc tax_calculator.c -o tax_calculator
```

### Run

```bash
./tax_calculator
```

---

##  Example Input

```
Enter your Annual Income (₹): 1200000
```

##  Output

```
Total Tax Payable: ₹0.00
```

---

##  File Structure

```
📁 Income-Tax-Calculator
 ├── tax_calculator.c
 └── README.md
```

---

##  Mentions

Developed with the help of one of my friend @Roushan-2104
