#include <stdio.h>
#include <math.h>

/*
============================================================
        INCOME TAX CALCULATOR (FY 2025–26)
                 NEW TAX REGIME
============================================================

Tax Slabs:
------------------------------------------------------------
Annual Income (₹)           Tax Rate
------------------------------------------------------------
Up to 4,00,000                NIL
4,00,001 – 8,00,000            5%
8,00,001 – 12,00,000           10%
12,00,001 – 16,00,000          15%
16,00,001 – 20,00,000          20%
20,00,001 – 24,00,000          25%
Above 24,00,000                30%
------------------------------------------------------------

Other Rules:
• Standard Deduction : ₹75,000
• Rebate (Sec 87A)   : Max ₹60,000 (Income ≤ ₹12L)
• Marginal Relief    : Up to ₹12.75L
• Health & Edu Cess  : 4%
• Surcharge          : Applicable for high income
============================================================
*/

/*----------------------------------------------------------
  Macro: MIN
  Purpose: Returns the smaller of two values
  Used for rebate and marginal relief calculations
----------------------------------------------------------*/
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/*----------------------------------------------------------
  Function: taxSlab
  Input   : Annual Income
  Output  : Final Tax Payable
----------------------------------------------------------*/
float taxSlab(float annIncome)
{
    /* ---------- BASIC VARIABLES ---------- */
    int standardDeduction = 75000;     // Flat standard deduction
    float netTaxableIncome;            // Income after deduction
    float grossTax = 0;                // Tax before rebate & cess
    float finalTax = 0;                // Final tax payable
    float excessIncome;                // For marginal relief
    float maxRebate = 60000;           // Section 87A rebate
    float rebateApplied = 0;

    /* ---------- STEP 1: NET TAXABLE INCOME ---------- */
    netTaxableIncome = annIncome - standardDeduction;

    /* ---------- STEP 2: SLAB-WISE TAX CALCULATION ---------- */

    // Slab 1: Up to ₹4,00,000 → No tax
    if (netTaxableIncome <= 400000)
    {
        grossTax = 0;
    }

    // Slab 2: ₹4L – ₹8L → 5%
    else if (netTaxableIncome <= 800000)
    {
        grossTax = (netTaxableIncome - 400000) * 0.05;
    }

    // Slab 3: ₹8L – ₹12L → 10%
    else if (netTaxableIncome <= 1200000)
    {
        grossTax = (netTaxableIncome - 800000) * 0.10 + 20000;
    }

    // Slab 4: ₹12L – ₹16L → 15%
    else if (netTaxableIncome <= 1600000)
    {
        grossTax = (netTaxableIncome - 1200000) * 0.15 + 60000;
    }

    // Slab 5: ₹16L – ₹20L → 20%
    else if (netTaxableIncome <= 2000000)
    {
        grossTax = (netTaxableIncome - 1600000) * 0.20 + 120000;
    }

    // Slab 6: ₹20L – ₹24L → 25%
    else if (netTaxableIncome <= 2400000)
    {
        grossTax = (netTaxableIncome - 2000000) * 0.25 + 200000;
    }

    // Slab 7: Above ₹24L → 30%
    else
    {
        grossTax = (netTaxableIncome - 2400000) * 0.30 + 300000;

        /* ---------- STEP 3: SURCHARGE ---------- */
        if (netTaxableIncome > 5000000 && netTaxableIncome <= 10000000)
            grossTax += grossTax * 0.10;
        else if (netTaxableIncome <= 20000000)
            grossTax += grossTax * 0.15;
        else if (netTaxableIncome <= 50000000)
            grossTax += grossTax * 0.25;
        else
            grossTax += grossTax * 0.25;   // Capped in new regime
    }

    /* ---------- STEP 4: REBATE & MARGINAL RELIEF ---------- */

    // Case 1: Income up to ₹12L → Full rebate
    if (netTaxableIncome <= 1200000)
    {
        rebateApplied = MIN(grossTax, maxRebate);
        finalTax = (grossTax - rebateApplied) * 0.04;
    }

    // Case 2: ₹12L – ₹12.75L → Marginal relief
    else if (netTaxableIncome <= 1275000)
    {
        excessIncome = netTaxableIncome - 1200000;
        grossTax = MIN(grossTax, excessIncome);
        finalTax = grossTax + (grossTax * 0.04);
    }

    // Case 3: Above ₹12.75L → Normal tax + cess
    else
    {
        finalTax = grossTax + (grossTax * 0.04);
    }

    return finalTax;
}

/*----------------------------------------------------------
  MAIN FUNCTION
----------------------------------------------------------*/
int main()
{
    float annualIncome;
    float payableTax;

    printf("Enter your Annual Income (₹): ");
    scanf("%f", &annualIncome);

    payableTax = taxSlab(annualIncome);

    printf("Total Tax Payable: ₹%.2f\n", payableTax);

    return 0;
}
