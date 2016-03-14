#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	while (1) {
		int va, pa, pde_idx, pde_ctx, pte_idx, pte_ctx;
		if (scanf("va %x, pa %x\n", &va, &pa) != EOF) {
			pde_idx = va >> 22;
			pde_ctx = ((pde_idx - 0x300 + 1) << 12) | 0x03;
			pte_idx = (va >> 12) & 1023;
			pte_ctx = ((pa >> 12) << 12) | 0x03;
			printf("va: %x pa: %x pde_idx: %x pde_ctx: %x pte_idx: %x pte_ctx: %x\n", va, pa, pde_idx, pde_ctx, pte_idx, pte_ctx);
		}
		else 
			break;
	}
}